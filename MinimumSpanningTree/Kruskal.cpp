#include "Kruskal.h"
#include "Prim.h"

Result Kruskal::Solve(const Graph& graph) const
{
	Prim prim;
	return prim.Solve(graph);
}
