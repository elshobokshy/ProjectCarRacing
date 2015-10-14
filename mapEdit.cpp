#include "mapEdit.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

#include "RoadBlock.hpp"
#include "Map.hpp"

#include <iostream>



namespace mapEdit
{

	void getEvents(sf::RenderWindow &window)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					exit(EXIT_SUCCESS);
					break;
				case sf::Event::KeyPressed:
					switch(event.key.code)
					{
						case sf::Keyboard::Escape:
							exit(EXIT_SUCCESS);
							break;
						default:
							break;
					}
					break;
				case sf::Event::KeyReleased:
					break;
				default:
					break;
			}
		}	
	}




	void mapEdit(sf::RenderWindow &window)
	{
		RoadBlock cursorBlock(RoadBlock::straight, RoadBlock::standard, sf::Vector2f(200, 200)); //block that will be drawn under the cusor, for the user to know what he is going to use


	
		while(true)
		{
			mapEdit::getEvents(window);
			
			/*sf::Vector2i cursorBlockPosition = sf::Mouse::getPosition(window); //get the position, relative to the window
			cursorBlock.setPosition( float(cursorBlockPosition.x), float(cursorBlockPosition.y) );

			std::cout<< cursorBlockPosition.x<< " ; "<< cursorBlockPosition.y<< '\n';*/

			//edit the map
		

		
			window.clear(sf::Color::Black);
			//game display
			window.draw(cursorBlock);

			window.display();
		}
	
	}


}
