#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"
#include "collision.hpp"
#include "mapEdit.hpp"
#include <iostream>


int main(int argc, char **argv)
{

	sf::ContextSettings winSettings;
	winSettings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing", sf::Style::Default, winSettings);

	game::game(window);

	
	
	return EXIT_SUCCESS;
}
