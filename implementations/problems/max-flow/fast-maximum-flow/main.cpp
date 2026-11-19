#include "../../../flow-network/Dinic.hpp"
#include "../../../flow-network/EdmondsKarp.hpp"
#include "../../../flow-network/FordFulkerson.hpp"
#include "../../../flow-network/HopcroftKarp.hpp"
#include "../../../flow-network/Kuhn.hpp"
#include "../../../flow-network/MPM.hpp"
#include "../../../flow-network/PushRelabel.hpp"
#include "../../../flow-network/PushRelabelImproved.hpp"
#include <iostream>

using FlowSolver = PushRelabelImproved;

void task()
{
	Size num_nodes, num_edges;
	if (!(std::cin >> num_nodes >> num_edges))
		return;

	const auto fn = FlowSolver::create(num_nodes);
	for (Size k = 0; k < num_edges; ++k)
	{
		Size u, v;
		Long cap;
		std::cin >> u >> v >> cap;
		if (u == v)
			continue;
		fn->add_edge(u - 1, v - 1, cap);
		fn->add_edge(v - 1, u - 1, cap);
	}

	std::cout << fn->compute_max_flow(0, num_nodes - 1) << '\n';
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	task();
	return 0;
}
