#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"

int main()
{
    // Get screen resolution for SFML window
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	// sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "AI Pathfinding", sf::Style::Fullscreen);
	
	// Using a fixed size render window
	sf::RenderWindow window(sf::VideoMode(512, 256), "Ai Pathfinding");

	// Master clock
	sf::Clock clock;

	// This array will define the tile indices
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	// Create the tilemap
	TileMap map;
	if (!map.load("tilemaps/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
	{
		return -1;
	}

	// Main game loop
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		// Draw the map
		window.clear();
		window.draw(map);
		window.display();
	}

	return 0;
}
