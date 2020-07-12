#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Get screen resolution for SFML window
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "AI Pathfinding", sf::Style::Fullscreen);

	// Main game loop
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		window.display();
	}

	return 0;
}
