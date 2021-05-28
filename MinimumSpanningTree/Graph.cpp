#include "Graph.h"

#include <cmath>

Graph::Graph(std::initializer_list<int> adjacencyMatrix)
	:
	_vertexCount(0),
	_adjacencyMatrix(adjacencyMatrix)
{
	std::size_t size = _adjacencyMatrix.size();
	double vertexCount = std::sqrt(size);

	_vertexCount = static_cast<int>(vertexCount);

	if (vertexCount != _vertexCount)
	{
		throw std::exception("Adjacency matrix is not square.");
	}
}

int Graph::VertexCount() const
{
	return _vertexCount;
}

int Graph::GetCost(int source, int target) const
{
	std::size_t index = source * _vertexCount + target;
	return _adjacencyMatrix[index];
}