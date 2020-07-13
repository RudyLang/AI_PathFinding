/* Using the TileMap Exaple provided here: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php */

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tilesetPath, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};
