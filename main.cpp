#include <SFML/Graphics/RenderWindow.hpp>
#include "game.hpp"
#include "collision.hpp"
#include "mapEdit.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics/Transform.hpp>



int main(int argc, char **argv)
{

	sf::ContextSettings winSettings;
	winSettings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car Racing", sf::Style::Default, winSettings);
	//window.setFramerateLimit(60);


	sf::Transform transf;
	transf.rotate(180, 128, 128);
	sf::Vector2f p(226, 224);
	p = transf.transformPoint(p);
	std::cout<< p.x<< " ; "<< p.y<< '\n';


	RoadBlock block(RoadBlock::corner, RoadBlock::standard);
	RoadBox box = block.getHitBox();
	const std::vector<collision::LineHitBox> lines = box.getLineArray();
	

	//std::cout<< ' ';
       	//return 	EXIT_SUCCESS;


	//replace the menu by program arguments for now
	if(argc >= 2)
	{
		if(std::string(argv[1]) == std::string("play"))
		{
			game::game(window);
		}
		else if(std::string(argv[1]) == std::string("edit"))
		{
			mapEdit::mapEdit(window);
		}
		else
		{
			std::cout<< "Wrong argument format.\n\"play\" or \"edit\" expected\n";
		}
	}
	else
	{
		game::game(window);
	}

	
	return EXIT_SUCCESS;
}
