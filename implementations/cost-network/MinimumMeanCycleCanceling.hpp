#ifndef MINIMUM_MEAN_CYCLE_CANCELING_HPP
#define MINIMUM_MEAN_CYCLE_CANCELING_HPP

#include "CostNetwork.hpp"
#include <algorithm>
#include <cstdint>
#include <queue>
#include <vector>

class MinimumMeanCycleCanceling : public CostNetwork
{
public:
	explicit MinimumMeanCycleCanceling(const Size n)
	    : CostNetwork(n), level(n), next_edge_ptr(n)
	{
	}

	static std::unique_ptr<CostNetwork> create(const Size n)
	{
		return std::make_unique<MinimumMeanCycleCanceling>(n);
	}

	std::unique_ptr<CostNetwork> make(const Size n) const override
	{
		return std::make_unique<MinimumMeanCycleCanceling>(n);
	}

	std::unique_ptr<CostNetwork> clone() const override
	{
		return std::make_unique<MinimumMeanCycleCanceling>(*this);
	}

	Long compute_min_cost_max_flow(const Size source, const Size sink) override
	{
		if (size == 0 || source >= size || sink >= size)
			return 0;

		saturate_max_flow(source, sink);

		while (cancel_min_mean_cycles())
		{
			continue;
		}

		Long total_cost = 0;
		for (Size i = 0; i < edges.size(); i += 2)
			total_cost += edges[i].flow * edges[i].cost;
		return total_cost;
	}

private:
	__extension__ using Int128 = __int128;
	__extension__ using UInt128 = unsigned __int128;
	static constexpr Int128 INF128 = static_cast<Int128>(1) << 120;

	struct ResidualArc
	{
		Size from;
		Size to;
		Long cost;
	};

	std::vector<Size> level;
	std::vector<Size> next_edge_ptr;

	[[nodiscard]] static UInt128 gcd_u128(UInt128 a, UInt128 b)
	{
		while (b != 0)
		{
			const UInt128 r = a % b;
			a = b;
			b = r;
		}
		return a;
	}

	void saturate_max_flow(const Size source, const Size sink)
	{
		if (source == sink)
			return;

		while (bfs_level(source, sink))
		{
			std::fill(next_edge_ptr.begin(), next_edge_ptr.end(), 0);
			while (dfs_push(source, sink, INF) > 0)
			{
				continue;
			}
		}
	}

	bool bfs_level(const Size source, const Size sink)
	{
		std::fill(level.begin(), level.end(), MAX);
		std::queue<Size> queue;

		level[source] = 0;
		queue.push(source);

		while (!queue.empty())
		{
			const Size current = queue.front();
			queue.pop();

			for (const Size edge_id : adjacency[current])
			{
				const Size next = edges[edge_id].to;
				if (level[next] != MAX || get_residual_capacity(edge_id) <= 0)
					continue;

				level[next] = level[current] + 1;
				queue.push(next);
			}
		}

		return level[sink] != MAX;
	}

	Long dfs_push(const Size current, const Size sink, const Long pushed)
	{
		if (current == sink)
			return pushed;

		for (Size &ptr = next_edge_ptr[current]; ptr < adjacency[current].size();
		     ++ptr)
		{
			const Size edge_id = adjacency[current][ptr];
			const Size next = edges[edge_id].to;
			const Long residual = get_residual_capacity(edge_id);

			if (level[current] + 1 != level[next] || residual <= 0)
				continue;

			const Long bottleneck = std::min(pushed, residual);
			const Long transmitted = dfs_push(next, sink, bottleneck);

			if (transmitted == 0)
				continue;

			push_flow(edge_id, transmitted);
			return transmitted;
		}

		return 0;
	}

	bool cancel_min_mean_cycles()
	{
		std::vector<ResidualArc> active_arcs;
		active_arcs.reserve(edges.size());
		for (Size edge_id = 0; edge_id < edges.size(); ++edge_id)
		{
			if (get_residual_capacity(edge_id) > 0)
			{
				active_arcs.push_back(
				    {edges[edge_id].from, edges[edge_id].to, edges[edge_id].cost}
				);
			}
		}

		if (active_arcs.empty())
			return false;

		const Size n = size;
		std::vector<Int128> dp((n + 1) * n, INF128);
		for (Size v = 0; v < n; ++v)
			dp[v] = 0;

		for (Size k = 0; k < n; ++k)
		{
			bool any_finite = false;
			const Size prev_off = k * n;
			const Size next_off = (k + 1) * n;

			for (const auto &arc : active_arcs)
			{
				const Int128 du = dp[prev_off + arc.from];
				if (du == INF128)
					continue;

				const Int128 cand = du + static_cast<Int128>(arc.cost);
				if (cand < dp[next_off + arc.to])
				{
					dp[next_off + arc.to] = cand;
					any_finite = true;
				}
			}

			if (!any_finite)
				return false;
		}

		bool has_cycle = false;
		Int128 best_p = 0;
		Int128 best_q = 1;
		const Size last_off = n * n;

		for (Size v = 0; v < n; ++v)
		{
			const Int128 dn = dp[last_off + v];
			if (dn == INF128)
				continue;

			bool has_v = false;
			Int128 v_p = 0;
			Int128 v_q = 1;

			for (Size k = 0; k < n; ++k)
			{
				const Int128 dk = dp[k * n + v];
				if (dk == INF128)
					continue;

				const Int128 num = dn - dk;
				const Int128 den = static_cast<Int128>(n - k);

				if (!has_v || num * v_q > v_p * den)
				{
					v_p = num;
					v_q = den;
					has_v = true;
				}
			}

			if (has_v && (!has_cycle || v_p * best_q < best_p * v_q))
			{
				best_p = v_p;
				best_q = v_q;
				has_cycle = true;
			}
		}

		if (!has_cycle || best_p >= 0)
			return false;

		const UInt128 u_neg_p = static_cast<UInt128>(-best_p);
		const UInt128 u_q = static_cast<UInt128>(best_q);
		const UInt128 g = gcd_u128(u_neg_p, u_q);
		best_p = -static_cast<Int128>(u_neg_p / g);
		best_q = static_cast<Int128>(u_q / g);

		std::vector<Int128> pi(n, INF128);
		for (Size v = 0; v < n; ++v)
		{
			Int128 min_val = INF128;
			for (Size k = 0; k <= n; ++k)
			{
				const Int128 dk = dp[k * n + v];
				if (dk == INF128)
					continue;

				const Int128 val = best_q * dk - static_cast<Int128>(k) * best_p;
				if (val < min_val)
					min_val = val;
			}
			pi[v] = min_val;
		}

		return cancel_tight_cycles(best_p, best_q, pi);
	}

	bool cancel_tight_cycles(
	    const Int128 p, const Int128 q, const std::vector<Int128> &pi
	)
	{
		auto is_tight = [&](const Size edge_id) -> bool {
			if (get_residual_capacity(edge_id) <= 0)
				return false;
			const Size u = edges[edge_id].from;
			const Size v = edges[edge_id].to;
			const Int128 w_shifted = q * static_cast<Int128>(edges[edge_id].cost) -
			                         p;
			return w_shifted + pi[u] - pi[v] == 0;
		};

		std::vector<std::uint8_t> state(size, 0);
		std::vector<Size> current_arc(size, 0);
		std::vector<Size> in_edge(size, MAX);
		std::vector<Size> stack_pos(size, MAX);
		std::vector<Size> stack;
		stack.reserve(size);

		bool canceled = false;

		for (Size start = 0; start < size; ++start)
		{
			if (state[start] != 0)
				continue;

			state[start] = 1;
			stack_pos[start] = 0;
			in_edge[start] = MAX;
			stack.push_back(start);

			while (!stack.empty())
			{
				const Size u = stack.back();
				Size &ptr = current_arc[u];

				while (ptr < adjacency[u].size())
				{
					const Size eid = adjacency[u][ptr];
					if (!is_tight(eid) || state[edges[eid].to] == 2)
					{
						++ptr;
						continue;
					}
					break;
				}

				if (ptr == adjacency[u].size())
				{
					state[u] = 2;
					stack_pos[u] = MAX;
					stack.pop_back();
					if (!stack.empty())
						++current_arc[stack.back()];
					continue;
				}

				const Size eid = adjacency[u][ptr];
				const Size v = edges[eid].to;

				if (state[v] == 0)
				{
					state[v] = 1;
					stack_pos[v] = stack.size();
					in_edge[v] = eid;
					stack.push_back(v);
				}
				else
				{
					const Size pos = stack_pos[v];
					Long bottleneck = get_residual_capacity(eid);
					for (Size i = pos + 1; i < stack.size(); ++i)
					{
						bottleneck = std::min(
						    bottleneck, get_residual_capacity(in_edge[stack[i]])
						);
					}

					push_flow(eid, bottleneck);
					for (Size i = pos + 1; i < stack.size(); ++i)
						push_flow(in_edge[stack[i]], bottleneck);

					canceled = true;

					Size unwind_to = stack.size() - 1;
					for (Size i = pos; i + 1 < stack.size(); ++i)
					{
						if (get_residual_capacity(in_edge[stack[i + 1]]) == 0)
						{
							unwind_to = i;
							break;
						}
					}

					while (stack.size() - 1 > unwind_to)
					{
						const Size w = stack.back();
						state[w] = 0;
						stack_pos[w] = MAX;
						in_edge[w] = MAX;
						stack.pop_back();
					}
				}
			}
		}

		return canceled;
	}
};

#endif // MINIMUM_MEAN_CYCLE_CANCELING_HPP
