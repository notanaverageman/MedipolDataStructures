#pragma once

#include "MinimumSpanningTreeSolver.h"

class Kruskal : public MinimumSpanningTreeSolver
{
public:
	Result Solve(const Graph& graph) const override;

	const char* Name() const override
	{
		return "Kruskal";
	}
};
