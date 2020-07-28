#include <SFML/Graphics.hpp>

void GetEdges(sf::VertexArray& nodes);

void StoreEdges();

size_t HashEdges(std::pair<sf::Vector2f, sf::Vector2f> coordinates);
