#pragma once

#include "Edge.h"

#include <unordered_set>
#include <string>

class Result
{
public:
	Result();
	Result(bool isSuccessful, std::string errorMessage, std::initializer_list<Edge> edges);

	void SetSuccess(bool success, std::string errorMessage = "");
	bool IsSuccessful() const;
	const std::string& ErrorMessage() const;

	void AddEdge(Edge edge);
	const std::unordered_set<Edge>& Edges() const;

	friend bool operator==(const Result& lhs, const Result& rhs);
	friend bool operator!=(const Result& lhs, const Result& rhs);
	
private:
	bool _isSuccessful;
	std::string _errorMessage;

	std::unordered_set<Edge> _edges;
};