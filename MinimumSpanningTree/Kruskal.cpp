#include "Kruskal.h"

Result Kruskal::Solve(const Graph& graph) const
{
	Result result;
	
	int vertexCount = graph.VertexCount();

	if (vertexCount == 0)
	{
		result.SetSuccess(false, "Graph is empty.");
		return result;
	}
	
	result.SetSuccess(false, "Not implemented.");

	return result;
}
