#pragma once

#include <vector>

class Graph
{
public:
	Graph(std::initializer_list<int> adjacencyMatrix);

	int VertexCount() const;
	int GetCost(int source, int target) const;

private:
	int _vertexCount;
	std::vector<int> _adjacencyMatrix;
};
