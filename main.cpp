#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"
#include "mapEdit.hpp"

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing");

	mapEdit::mapEdit(window);
	//game(window);

	return EXIT_SUCCESS;
}
