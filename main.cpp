#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"
#include "mapEdit.hpp"

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing");

	#ifdef _WIN32
	game(window);
	#endif
	
	#ifdef __gnu_linux__
	mapEdit::mapEdit(window);
	//game(window);

	return EXIT_SUCCESS;
}
