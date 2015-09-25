#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"


int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing");

	//menu
	game(window);
	
	// \menu

	return EXIT_SUCCESS;
}
