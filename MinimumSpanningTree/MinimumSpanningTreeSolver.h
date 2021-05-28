#pragma once

#include "Graph.h"
#include "Result.h"

class MinimumSpanningTreeSolver
{
public:
	virtual ~MinimumSpanningTreeSolver() = default;

	virtual Result Solve(const Graph& graph) const = 0;
	virtual const char* Name() const = 0;
};
