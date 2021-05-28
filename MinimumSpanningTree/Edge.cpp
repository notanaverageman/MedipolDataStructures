#include "Edge.h"

bool operator==(const Edge& lhs, const Edge& rhs)
{
	return lhs.Source == rhs.Source
		&& lhs.Target == rhs.Target
		&& lhs.Cost == rhs.Cost;
}

bool operator!=(const Edge& lhs, const Edge& rhs)
{
	return !(lhs == rhs);
}