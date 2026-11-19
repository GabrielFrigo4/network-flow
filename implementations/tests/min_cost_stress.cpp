#include "../cost-network/CancelAndTighten.hpp"
#include "../cost-network/CycleCanceling.hpp"
#include "../cost-network/MinimumMeanCycleCanceling.hpp"
#include "../cost-network/NetworkSimplex.hpp"
#include "../cost-network/SuccessiveShortestDijkstra.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <queue>
#include <random>
#include <string>
#include <vector>

struct TestArc
{
	Size u;
	Size v;
	Long cap;
	Long cost;
};

struct TestCase
{
	std::string name;
	Size n;
	Size source;
	Size sink;
	std::vector<TestArc> arcs;
};

__extension__ using Int128 = __int128;

[[noreturn]] static void fail_test(
    const std::string &case_name, const std::string &algo, const std::string &reason
)
{
	std::cerr << "[FAIL] " << case_name << " (" << algo << "): " << reason << "\n";
	std::exit(1);
}

static void populate_network(CostNetwork &net, const TestCase &tc)
{
	for (const auto &arc : tc.arcs)
		net.add_edge(arc.u, arc.v, arc.cap, arc.cost);
}

static void verify_solution(
    const CostNetwork &net, const TestCase &tc, const std::string &algo,
    const Long reported_cost
)
{
	const Size n = net.get_size();
	const auto &edges = net.get_edges();
	const auto &adj = net.get_adjacency();

	if (n != tc.n)
		fail_test(tc.name, algo, "network size mismatch");
	if (edges.size() != tc.arcs.size() * 2)
		fail_test(tc.name, algo, "edge count mismatch");

	std::vector<Int128> balance(n, 0);
	Int128 exact_cost = 0;

	for (Size i = 0; i < edges.size(); i += 2)
	{
		const auto &fwd = edges[i];
		const auto &rev = edges[i + 1];

		if (fwd.flow < 0 || fwd.flow > fwd.capacity)
			fail_test(tc.name, algo, "capacity bound violated");
		if (rev.flow != -fwd.flow)
			fail_test(tc.name, algo, "skew-symmetry violated");

		balance[fwd.from] += static_cast<Int128>(fwd.flow);
		balance[fwd.to] -= static_cast<Int128>(fwd.flow);
		exact_cost += static_cast<Int128>(fwd.flow) * static_cast<Int128>(fwd.cost);
	}

	if (exact_cost != static_cast<Int128>(reported_cost))
		fail_test(tc.name, algo, "reported cost != exact flow cost");

	if (n > 0 && tc.source < n && tc.sink < n)
	{
		const Long reported_flow = net.get_total_flow(tc.source);
		if (tc.source == tc.sink)
		{
			if (reported_flow != 0)
				fail_test(tc.name, algo, "nonzero total flow when source == sink");
			for (Size v = 0; v < n; ++v)
			{
				if (balance[v] != 0)
					fail_test(tc.name, algo, "flow conservation violated");
			}
		}
		else
		{
			if (balance[tc.source] != static_cast<Int128>(reported_flow))
				fail_test(tc.name, algo, "source balance mismatch");
			if (balance[tc.sink] != -static_cast<Int128>(reported_flow))
				fail_test(tc.name, algo, "sink balance mismatch");
			for (Size v = 0; v < n; ++v)
			{
				if (v != tc.source && v != tc.sink && balance[v] != 0)
					fail_test(tc.name, algo, "flow conservation violated");
			}

			std::vector<bool> vis(n, false);
			std::queue<Size> q;
			vis[tc.source] = true;
			q.push(tc.source);

			while (!q.empty())
			{
				const Size u = q.front();
				q.pop();
				for (const Size eid : adj[u])
				{
					const Long res = edges[eid].capacity - edges[eid].flow;
					const Size v = edges[eid].to;
					if (res > 0 && !vis[v])
					{
						vis[v] = true;
						q.push(v);
					}
				}
			}

			if (vis[tc.sink])
				fail_test(tc.name, algo, "residual s-t path still exists");
		}
	}

	std::vector<Int128> dist(n, 0);
	for (Size iter = 0; iter < n; ++iter)
	{
		bool changed = false;
		for (Size eid = 0; eid < edges.size(); ++eid)
		{
			if (edges[eid].capacity - edges[eid].flow <= 0)
				continue;
			const Size u = edges[eid].from;
			const Size v = edges[eid].to;
			const Int128 cand = dist[u] + static_cast<Int128>(edges[eid].cost);
			if (cand < dist[v])
			{
				dist[v] = cand;
				changed = true;
			}
		}
		if (!changed)
			break;
		if (iter + 1 == n)
			fail_test(tc.name, algo, "negative residual cycle remains");
	}
}

static void check_case(
    const TestCase &tc, const bool check_dijkstra, const bool check_cc = true
)
{
	auto ns = NetworkSimplex::create(tc.n);
	auto mmcc = MinimumMeanCycleCanceling::create(tc.n);
	auto ct = CancelAndTighten::create(tc.n);

	populate_network(*ns, tc);
	populate_network(*mmcc, tc);
	populate_network(*ct, tc);

	const Long ns_cost = ns->compute_min_cost_max_flow(tc.source, tc.sink);
	const Long ns_flow = (tc.n > 0 && tc.source < tc.n)
	                         ? ns->get_total_flow(tc.source)
	                         : 0;

	if (check_cc)
	{
		auto cc = CycleCanceling::create(tc.n);
		populate_network(*cc, tc);
		const Long cc_cost = cc->compute_min_cost_max_flow(tc.source, tc.sink);
		const Long cc_flow = (tc.n > 0 && tc.source < tc.n)
		                         ? cc->get_total_flow(tc.source)
		                         : 0;

		if (cc_flow != ns_flow || cc_cost != ns_cost)
			fail_test(tc.name, "CycleCanceling", "disagrees with NetworkSimplex");
	}

	const Long mmcc_cost = mmcc->compute_min_cost_max_flow(tc.source, tc.sink);
	const Long mmcc_flow = (tc.n > 0 && tc.source < tc.n)
	                           ? mmcc->get_total_flow(tc.source)
	                           : 0;

	if (mmcc_flow != ns_flow || mmcc_cost != ns_cost)
		fail_test(tc.name, "MinimumMeanCycleCanceling", "disagrees with reference");
	verify_solution(*mmcc, tc, "MinimumMeanCycleCanceling", mmcc_cost);

	const Long ct_cost = ct->compute_min_cost_max_flow(tc.source, tc.sink);
	const Long ct_flow = (tc.n > 0 && tc.source < tc.n)
	                         ? ct->get_total_flow(tc.source)
	                         : 0;

	if (ct_flow != ns_flow || ct_cost != ns_cost)
		fail_test(tc.name, "CancelAndTighten", "disagrees with reference");
	verify_solution(*ct, tc, "CancelAndTighten", ct_cost);

	if (check_dijkstra && tc.source != tc.sink)
	{
		auto ssd = SuccessiveShortestDijkstra::create(tc.n);
		populate_network(*ssd, tc);
		const Long ssd_cost = ssd->compute_min_cost_max_flow(tc.source, tc.sink);
		const Long ssd_flow = ssd->get_total_flow(tc.source);
		if (ssd_flow != ns_flow || ssd_cost != ns_cost)
			fail_test(
			    tc.name, "SuccessiveShortestDijkstra", "disagrees with reference"
			);
	}
}

static void check_polymorphic_api()
{
	auto proto_mmcc = MinimumMeanCycleCanceling::create(4);
	auto proto_ct = CancelAndTighten::create(4);

	auto made_mmcc = proto_mmcc->make(4);
	auto made_ct = proto_ct->make(4);

	const std::vector<TestArc> arcs = {
	    {0, 1, 5, 2},
	    {1, 2, 5, -3},
	    {2, 0, 5, -1},
	    {0, 2, 4, 4},
	    {2, 3, 6, 1},
	    {1, 3, 3, 5},
	};

	for (const auto &arc : arcs)
	{
		made_mmcc->add_edge(arc.u, arc.v, arc.cap, arc.cost);
		made_ct->add_edge(arc.u, arc.v, arc.cap, arc.cost);
	}

	auto cloned_mmcc = made_mmcc->clone();
	auto cloned_ct = made_ct->clone();

	const Long c1 = made_mmcc->compute_min_cost_max_flow(0, 3);
	const Long c2 = cloned_mmcc->compute_min_cost_max_flow(0, 3);
	const Long c3 = made_ct->compute_min_cost_max_flow(0, 3);
	const Long c4 = cloned_ct->compute_min_cost_max_flow(0, 3);

	if (c1 != c2 || c1 != c3 || c1 != c4)
		fail_test("polymorphic_clone_make", "API", "clone/make cost mismatch");

	if (made_mmcc->get_total_flow(0) != made_ct->get_total_flow(0) ||
	    cloned_mmcc->get_total_flow(0) != cloned_ct->get_total_flow(0))
		fail_test("polymorphic_clone_make", "API", "clone/make flow mismatch");

	auto empty_mmcc = MinimumMeanCycleCanceling::create(0);
	auto empty_ct = CancelAndTighten::create(0);
	if (empty_mmcc->compute_min_cost_max_flow(0, 0) != 0 ||
	    empty_ct->compute_min_cost_max_flow(0, 0) != 0)
		fail_test("empty_graph", "API", "expected 0 cost on size 0");
}

static std::vector<TestCase> build_edge_cases()
{
	std::vector<TestCase> cases;

	cases.push_back({"single_node_empty", 1, 0, 0, {}});
	cases.push_back({"single_node_zero_loop", 1, 0, 0, {{0, 0, 10, 0}}});
	cases.push_back({"single_node_pos_loop", 1, 0, 0, {{0, 0, 10, 7}}});
	cases.push_back({"single_node_neg_loop", 1, 0, 0, {{0, 0, 10, -7}}});
	cases.push_back(
	    {"single_node_parallel_loops",
	     1,
	     0,
	     0,
	     {{0, 0, 4, -5}, {0, 0, 3, 2}, {0, 0, 6, -1}}}
	);

	cases.push_back({"two_nodes_disconnected", 2, 0, 1, {}});
	cases.push_back({"two_nodes_zero_cap", 2, 0, 1, {{0, 1, 0, -10}}});
	cases.push_back({"two_nodes_reverse_only", 2, 0, 1, {{1, 0, 10, -5}}});
	cases.push_back({"two_nodes_neg_cycle", 2, 0, 1, {{0, 1, 5, 0}, {1, 0, 3, -1}}});
	cases.push_back(
	    {"two_nodes_source_eq_sink_neg_cycle",
	     2,
	     0,
	     0,
	     {{0, 1, 5, -2}, {1, 0, 4, -3}}}
	);
	cases.push_back(
	    {"two_nodes_parallel",
	     2,
	     0,
	     1,
	     {{0, 1, 3, 10}, {0, 1, 4, -2}, {0, 1, 5, 0}, {0, 1, 2, 10}}}
	);

	cases.push_back(
	    {"disconnected_neg_cycle",
	     5,
	     0,
	     1,
	     {{0, 1, 5, 3}, {2, 3, 4, -5}, {3, 4, 4, -5}, {4, 2, 3, 2}}}
	);
	cases.push_back(
	    {"no_st_path_with_neg_cycle",
	     4,
	     0,
	     3,
	     {{0, 1, 5, 1}, {1, 2, 5, -3}, {2, 0, 5, -1}}}
	);

	cases.push_back(
	    {"tied_paths_diamond",
	     4,
	     0,
	     3,
	     {{0, 1, 4, 2},
	      {1, 3, 4, 3},
	      {0, 2, 4, 1},
	      {2, 3, 4, 4},
	      {1, 2, 4, 0},
	      {2, 1, 4, 0}}}
	);

	cases.push_back(
	    {"chaturvedi_mcconnell_asymmetric_1",
	     5,
	     0,
	     4,
	     {{0, 0, 4, -1},
	      {0, 1, 4, -100},
	      {1, 2, 4, 10},
	      {2, 1, 4, -20},
	      {1, 3, 4, -50},
	      {3, 4, 4, 5},
	      {0, 4, 2, 0}}}
	);
	cases.push_back(
	    {"chaturvedi_mcconnell_asymmetric_2",
	     6,
	     0,
	     5,
	     {{0, 1, 6, 0},
	      {1, 2, 6, -5},
	      {2, 0, 6, -4},
	      {0, 3, 5, -100},
	      {3, 4, 5, -2},
	      {4, 3, 5, -1},
	      {3, 5, 3, 1},
	      {2, 5, 4, 2}}}
	);
	cases.push_back(
	    {"close_fractional_means",
	     8,
	     0,
	     7,
	     {{0, 1, 3, -1},
	      {1, 2, 3, 0},
	      {2, 0, 3, 0},
	      {3, 4, 3, -2},
	      {4, 5, 3, 0},
	      {5, 6, 3, 0},
	      {6, 7, 3, 0},
	      {7, 3, 3, 0},
	      {0, 3, 2, 5},
	      {2, 7, 4, 1}}}
	);

	cases.push_back(
	    {"large_costs_mixed",
	     5,
	     0,
	     4,
	     {{0, 1, 10, 1000000000LL},
	      {1, 2, 10, -1000000000LL},
	      {2, 3, 10, -1},
	      {3, 1, 10, 0},
	      {0, 4, 5, 999999999LL},
	      {2, 4, 7, 1}}}
	);
	cases.push_back(
	    {"all_zero_costs",
	     5,
	     0,
	     4,
	     {{0, 1, 5, 0}, {1, 2, 5, 0}, {2, 3, 5, 0}, {3, 4, 5, 0}, {3, 1, 5, 0}}}
	);

	return cases;
}

static TestCase make_random_case(
    std::mt19937_64 &rng, const std::string &name, const Size n, const Size m,
    const Long max_cap, const Long min_cost, const Long max_cost,
    const bool allow_self_loops, const bool force_same_st
)
{
	std::uniform_int_distribution<Size> node_dist(0, n - 1);
	std::uniform_int_distribution<Long> cap_dist(0, max_cap);
	std::uniform_int_distribution<Long> cost_dist(min_cost, max_cost);

	Size s = node_dist(rng);
	Size t = node_dist(rng);
	if (!force_same_st && n >= 2 && s == t)
		t = (s + 1 + (rng() % (n - 1))) % n;
	if (force_same_st)
		t = s;

	std::vector<TestArc> arcs;
	arcs.reserve(m);
	for (Size i = 0; i < m; ++i)
	{
		Size u = node_dist(rng);
		Size v = node_dist(rng);
		if (!allow_self_loops && n >= 2 && u == v)
			v = (u + 1 + (rng() % (n - 1))) % n;
		arcs.push_back({u, v, cap_dist(rng), cost_dist(rng)});
	}

	return {name, n, s, t, std::move(arcs)};
}

static TestCase make_grid_case(
    std::mt19937_64 &rng, const std::string &name, const Size rows, const Size cols,
    const Long max_cap, const Long min_cost, const Long max_cost
)
{
	const Size n = rows * cols;
	std::uniform_int_distribution<Long> cap_dist(1, max_cap);
	std::uniform_int_distribution<Long> cost_dist(min_cost, max_cost);

	std::vector<TestArc> arcs;
	for (Size r = 0; r < rows; ++r)
	{
		for (Size c = 0; c < cols; ++c)
		{
			const Size u = r * cols + c;
			if (r + 1 < rows)
			{
				const Size v = (r + 1) * cols + c;
				arcs.push_back({u, v, cap_dist(rng), cost_dist(rng)});
				if (rng() % 3 == 0)
					arcs.push_back({v, u, cap_dist(rng), cost_dist(rng)});
			}
			if (c + 1 < cols)
			{
				const Size v = r * cols + (c + 1);
				arcs.push_back({u, v, cap_dist(rng), cost_dist(rng)});
				if (rng() % 3 == 0)
					arcs.push_back({v, u, cap_dist(rng), cost_dist(rng)});
			}
		}
	}

	return {name, n, 0, n - 1, std::move(arcs)};
}

int main()
{
	check_polymorphic_api();

	Size total_cases = 0;
	for (const auto &tc : build_edge_cases())
	{
		bool non_neg = true;
		for (const auto &a : tc.arcs)
		{
			if (a.cost < 0)
				non_neg = false;
		}
		check_case(tc, non_neg);
		++total_cases;
	}

	std::mt19937_64 rng(0x9E3779B97F4A7C15ULL);

	for (Size i = 0; i < 200; ++i)
	{
		const Size n = 3 + (rng() % 18);
		const Size m = n + (rng() % (2 * n + 1));
		const auto tc = make_random_case(
		    rng, "sparse_" + std::to_string(i), n, m, 200, -500, 500, false, false
		);
		check_case(tc, false);
		++total_cases;
	}

	for (Size i = 0; i < 150; ++i)
	{
		const Size n = 4 + (rng() % 12);
		const Size m = (n * n) / 2 + (rng() % (n * n / 2 + 1));
		const auto tc = make_random_case(
		    rng, "dense_" + std::to_string(i), n, m, 150, -300, 300, true, false
		);
		check_case(tc, false);
		++total_cases;
	}

	for (Size i = 0; i < 150; ++i)
	{
		const Size n = 4 + (rng() % 14);
		const Size m = n + (rng() % (3 * n + 1));
		const Long big = (i % 2 == 0) ? 1000000000LL : 1000000LL;
		const auto tc = make_random_case(
		    rng, "large_cost_" + std::to_string(i), n, m, 500, -big, big, true, false
		);
		check_case(tc, false);
		++total_cases;
	}

	for (Size i = 0; i < 100; ++i)
	{
		const Size rows = 2 + (rng() % 4);
		const Size cols = 2 + (rng() % 4);
		const auto tc = make_grid_case(
		    rng, "grid_" + std::to_string(i), rows, cols, 200, -100, 200
		);
		check_case(tc, false);
		++total_cases;
	}

	for (Size i = 0; i < 100; ++i)
	{
		const Size n = 1 + (rng() % 12);
		const Size m = rng() % (2 * n + 4);
		const bool same_st = (i % 2 == 0);
		const auto tc = make_random_case(
		    rng, "degenerate_" + std::to_string(i), n, m, 100, -50, 50, true, same_st
		);
		check_case(tc, false);
		++total_cases;
	}

	for (Size i = 0; i < 100; ++i)
	{
		const Size n = 3 + (rng() % 20);
		const Size m = n + (rng() % (3 * n + 1));
		const auto tc = make_random_case(
		    rng,
		    "nonneg_" + std::to_string(i),
		    n,
		    m,
		    1000,
		    0,
		    1000000000LL,
		    false,
		    false
		);
		check_case(tc, true);
		++total_cases;
	}

	{
		std::vector<TestArc> chain_arcs;
		const Size chain_n = 75;
		for (Size u = 0; u + 1 < chain_n; ++u)
			chain_arcs.push_back({u, u + 1, 20, 100000000LL});
		chain_arcs.push_back({chain_n - 1, 0, 10, -7500000001LL});
		chain_arcs.push_back({10, 5, 5, -1});
		chain_arcs.push_back({50, 40, 5, -3});
		check_case(
		    {"long_chain_karp_trigger",
		     chain_n,
		     0,
		     chain_n - 1,
		     std::move(chain_arcs)},
		    false,
		    false
		);
		++total_cases;
	}

	for (Size i = 0; i < 30; ++i)
	{
		const Size n = 65 + (rng() % 21);
		const Size m = 2 * n + (rng() % (2 * n));
		const auto tc = make_random_case(
		    rng,
		    "medium_karp_" + std::to_string(i),
		    n,
		    m,
		    500,
		    -1000000000LL,
		    1000000000LL,
		    false,
		    false
		);
		check_case(tc, false, false);
		++total_cases;
	}

	std::cout << "[PASS] min_cost_stress: " << total_cases
	          << " instances verified (MMCC & CancelAndTighten == reference).\n";
	return 0;
}
