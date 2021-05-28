#pragma once

#include <unordered_set>

struct Edge
{
	int Source;
	int Target;
	int Cost;

	friend bool operator==(const Edge& lhs, const Edge& rhs);
	friend bool operator!=(const Edge& lhs, const Edge& rhs);
};

namespace std
{
	template<>
	struct hash<Edge>
	{
		size_t operator()(const Edge& edge) const noexcept
		{
			std::size_t seed = 0x67E2C3FB;
			seed ^= (seed << 6) + (seed >> 2) + 0x3C3C4C72 + static_cast<std::size_t>(edge.Source);
			seed ^= (seed << 6) + (seed >> 2) + 0x782FFEA4 + static_cast<std::size_t>(edge.Target);
			seed ^= (seed << 6) + (seed >> 2) + 0x7612A2B4 + static_cast<std::size_t>(edge.Cost);

			return seed;
		}
	};
}