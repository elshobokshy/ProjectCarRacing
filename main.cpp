#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"


int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing");

	game(window);

	return EXIT_SUCCESS;
}
