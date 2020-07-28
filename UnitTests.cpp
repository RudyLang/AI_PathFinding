#include "pch.h"
#include "catch.h"

// Include function declarations here:
#include "Helpers.h"

TEST_CASE("Hash keys computed from edge coordinates", "HashEdges")
{
	// HashKey Test
	std::pair<sf::Vector2f, sf::Vector2f> testEdge;
	sf::Vector2f v1(16.5f, 24.f);
	sf::Vector2f v2(48.5f, 24.f);
	testEdge = std::make_pair(v1, v2);

	REQUIRE(HashEdges(testEdge) == 16244824);
}