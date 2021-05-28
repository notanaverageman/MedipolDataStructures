#include "Catch.h"
#include "TestCases.h"

#include "../MinimumSpanningTree/Prim.h"
#include "../MinimumSpanningTree/Kruskal.h"

SCENARIO("Minimum Spanning Tree Solvers", "[MinimumSpanningTree][Prim][Kruskal]")
{
	std::shared_ptr<MinimumSpanningTreeSolver> solver = GENERATE(
		as<std::shared_ptr<MinimumSpanningTreeSolver>>{},
		std::make_shared<Prim>(),
		std::make_shared<Kruskal>());

	INFO(std::string("Solver: ") + solver->Name())

	GIVEN("An empty graph")
	{
		Graph graph({});

		WHEN("Solver solves the graph")
		{
			Result result = solver->Solve(graph);

			THEN("Result should be unsuccessful and an error message should be returned.")
			{
				INFO(std::string("Error message: ") + result.ErrorMessage())
				CHECK(result == Result{ false, "Graph is empty.", {} });
			}
		}
	}

	GIVEN("A disconnected graph")
	{
		Graph graph({
			0, 4, 5, 0, 0, 0,
			4, 0, 3, 0, 0, 0,
			5, 3, 0, 0, 0, 0,
			0, 0, 0, 0, 6, 7,
			0, 0, 0, 6, 0, 1,
			0, 0, 0, 7, 1, 0,
			});

		WHEN("Solver solves the graph")
		{
			Result result = solver->Solve(graph);

			THEN("Result should be unsuccessful and an error message should be returned.")
			{
				INFO(std::string("Error message: ") + result.ErrorMessage())
				CHECK(result == Result{ false, "Could not find a suitable edge.", {} });
			}
		}
	}

	GIVEN("Non empty graphs")
	{
		const TestCase& testCase = GENERATE(from_range(TestCases));

		WHEN("Solver solves the graph")
		{
			const Graph& graph = testCase.Graph;
			const Result& expectedResult = testCase.ExpectedResult;

			Result result = solver->Solve(graph);

			THEN("Result should be same as the expected result.")
			{
				INFO(std::string("Error message: ") + result.ErrorMessage())
				CHECK(result == expectedResult);
			}
		}
	}
}