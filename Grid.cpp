#include "pch.h"
#include "Grid.h"

Graph::Graph() {};

Graph::Graph(std::vector<Edge> const& edges, int N)
{
	// Allocate only the number of elements needed
	adjacenyList.resize(N);

	// Add the edges to the graph (undirected)
	for (auto &edge : edges)
	{
		int source = edge.source;
		int destination = edge.destination;
		int weight = edge.weight;

		adjacenyList[source].push_back(std::make_pair(destination, weight));
		adjacenyList[destination].push_back(std::make_pair(source, weight));
	}
}

bool Graph::load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	// Resize the nodes vertex array to fit the level size
	m_nodes.setPrimitiveType(sf::Points);
	m_nodes.resize(height * width);

	// Populate the vertex array, with one node (point) per tile
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			int nodeNumber = tiles[i + j * width];

			// Get a pointer to the current tile's node
			sf::Vertex* point = &m_nodes[i + j * width];

			// Calculate midpoint for tile (point position)
			float midX = ((i * tileSize.x) * 2 + tileSize.x) / 2;
			float midY = ((j * tileSize.y) * 2 + tileSize.y) / 2;

			// Configure the position of the point
			point->position = sf::Vector2f(midX, midY);

			point->color = sf::Color::White;
		}
	}

	// Resize the edges vertex array to fit the level size
	m_edges.setPrimitiveType(sf::Lines);

	std::size_t numOfEdges = 2 * height * width + 2 * ((height - 1) + (width - 1)) - height - width; // Calculation for m x n grid
	m_edges.resize(numOfEdges);

	// Populate the vertex array, with every edge
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			int nodeNumber = tiles[i + j * width];

			// Get a pointer to the current line
			sf::Vertex* line = &m_edges[i + j * width];

			// Calculate the source and destination of the edge
			float sourceX = ((i * tileSize.x) * 2 + tileSize.x) / 2;
			float sourceY = ((j * tileSize.y) * 2 + tileSize.y) / 2;
			float destinationX = ((i * tileSize.x) * 2 + tileSize.x) / 2;
			float destinationY = ((j * tileSize.y) * 2 + tileSize.y) / 2;

			// Configure the position of the point
			line[0].position = sf::Vector2f(sourceX, sourceY);
			line[1].position = sf::Vector2f(destinationX, destinationY);

			line->color = sf::Color(255, 255, 255, 125);
		}
	}

	return 1;
}

void Graph::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply the transform
	states.transform *= getTransform();

	// Draw the vertex array
	target.draw(m_nodes, states);
	target.draw(m_edges, states);
}