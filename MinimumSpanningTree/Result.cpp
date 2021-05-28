#include "Result.h"

Result::Result()
	:
	_isSuccessful(false)
{
}

Result::Result(bool isSuccessful, std::string errorMessage, std::initializer_list<Edge> edges)
	:
	_isSuccessful(isSuccessful),
	_errorMessage(std::move(errorMessage)),
	_edges(edges)
{
}

void Result::SetSuccess(bool success, std::string errorMessage)
{
	_isSuccessful = success;
	_errorMessage = std::move(errorMessage);
}

bool Result::IsSuccessful() const
{
	return _isSuccessful;
}

const std::string& Result::ErrorMessage() const
{
	return _errorMessage;
}

void Result::AddEdge(Edge edge)
{
	_edges.insert(edge);
}

const std::unordered_set<Edge>& Result::Edges() const
{
	return _edges;
}

bool operator==(const Result& lhs, const Result& rhs)
{
	if (lhs._isSuccessful != rhs._isSuccessful)
	{
		return false;
	}

	if (lhs._errorMessage != rhs._errorMessage)
	{
		return false;
	}

	if (!lhs._isSuccessful)
	{
		// Do not check edges if the results are unsuccessful.
		return true;
	}

	return lhs._edges == rhs._edges;
}

bool operator!=(const Result& lhs, const Result& rhs)
{
	return !(lhs == rhs);
}
