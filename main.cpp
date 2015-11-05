#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"
#include "mapEdit.hpp"


int main(int argc, char **argv)
{
	sf::ContextSettings winSettings;
	winSettings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing", sf::Style::Default, winSettings);

	#ifdef _WIN32
	game::game(window);
	#endif
	
	#ifdef __gnu_linux__
	//mapEdit::mapEdit(window);
	game::game(window);
	#endif

	return EXIT_SUCCESS;
}
