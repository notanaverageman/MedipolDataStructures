#include "Prim.h"

Result Prim::Solve(const Graph& graph) const
{
	Result result;

	int vertexCount = graph.VertexCount();

	if (vertexCount == 0)
	{
		result.SetSuccess(false, "Graph is empty.");
		return result;
	}

	// Visited holds true for vertices that are visited already.
	std::vector<bool> isVisited(vertexCount, false);

	// Set the first vertice as visited to start.
	isVisited[0] = true;

	// When algorithm completes total number of edges will be one less than the number of vertices.
	int numberOfEdges = 0;

	while (numberOfEdges < vertexCount - 1)
	{
		int minimumSource = -1;
		int minimumTarget = -1;

		int minimumCost = std::numeric_limits<int>::max();

		// Iterate on source vertices.
		for (int source = 0; source < vertexCount; source++)
		{
			if (!isVisited[source])
			{
				// Skip non visited ones.
				continue;
			}

			// Iterate on target vertices.
			for (int target = 0; target < vertexCount; target++)
			{
				// Skip visited ones.
				if (isVisited[target])
				{
					continue;
				}

				int cost = graph.GetCost(source, target);

				// Skip non existing edges.
				if (cost <= 0)
				{
					continue;
				}

				if (cost < minimumCost)
				{
					minimumCost = cost;

					minimumSource = source;
					minimumTarget = target;
				}
			}
		}

		if (minimumSource < 0 || minimumTarget < 0)
		{
			result.SetSuccess(false, "Could not find a suitable edge.");
			return result;
		}

		// Store the result.
		Edge edge{ minimumSource, minimumTarget, minimumCost };
		result.AddEdge(edge);

		// Mark the target vertex as visited.
		isVisited[minimumTarget] = true;

		numberOfEdges++;
	}

	result.SetSuccess(true);
	return result;
}