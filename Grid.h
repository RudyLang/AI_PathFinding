/* Defines a Graph class that will represent our list using adjacency lists
https://www.techiedelight.com/graph-implementation-using-stl/
*/

#include <vector>
#include <SFML/Graphics.hpp>

typedef std::pair<int, int> Pair;

struct Edge
{
	int source;
	int destination;
	int weight;
};

class Graph : public sf::Drawable, public sf::Transformable
{
public:
	std::vector<std::vector<Pair>> adjacenyList;

	// Constructor
	Graph();
	Graph(std::vector<Edge> const& edges, int N);

	bool load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Use a vertex array to represent the nodes and edges
	sf::VertexArray m_nodes;
	sf::VertexArray m_edges;
};



