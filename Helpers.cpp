#include "pch.h"
#include <utility>
#include <string>
#include "Helpers.h"

typedef std::pair<sf::Vector2f, sf::Vector2f> coords;

void GetEdges(sf::VertexArray& nodes)
{
	// Define 8 edge directions
	/*
	2	3	4
	  \	| /
	1 -	o -	5
	  / | \
	8 	7	6
	*/
	coords edge1, edge2, edge3, edge4, edge5, edge6, edge7, edge8;

	// Iterate through each node
	for (std::size_t i = 0; i < nodes.getVertexCount() - 1; i++)
	{
		// Set the source for each edge to be the position of the node
		edge1.first =
		edge2.first =
		edge3.first =
		edge4.first =
		edge5.first =
		edge6.first =
		edge7.first =
		edge8.first = nodes[i].position;

		// Apply translation for each neighbouring node
		edge1.second = sf::Vector2f(nodes[i].position.x - 1, nodes[i].position.y);
		edge2.second = sf::Vector2f(nodes[i].position.x - 1, nodes[i].position.y + 1);
		edge3.second = sf::Vector2f(nodes[i].position.x, nodes[i].position.y + 1);
		edge4.second = sf::Vector2f(nodes[i].position.x + 1, nodes[i].position.y + 1);
		edge5.second = sf::Vector2f(nodes[i].position.x + 1, nodes[i].position.y);
		edge6.second = sf::Vector2f(nodes[i].position.x + 1, nodes[i].position.y - 1);
		edge7.second = sf::Vector2f(nodes[i].position.x, nodes[i].position.y - 1);
		edge8.second = sf::Vector2f(nodes[i].position.x - 1, nodes[i].position.y - 1);
	}
}

void StoreEdges()
{

}

// Generate a unique hash key for each pair of coordinates.
// Example: ([16.2f, 16.2f],[48.5f, 16.2f]) -> 16164816
size_t HashEdges(std::pair<sf::Vector2f, sf::Vector2f> coordinates)
{
	size_t coordKey = 0;

	std::string x1 = std::to_string((int)coordinates.first.x);
	std::string y1 = std::to_string((int)coordinates.first.y);
	std::string x2 = std::to_string((int)coordinates.second.x);
	std::string y2 = std::to_string((int)coordinates.second.y);

	// Concat string coordinates
	std::string strCoord = x1 + y1 + x2 + y2;

	// Convert string to size_t
	coordKey = stoi(strCoord);

	return coordKey;
}