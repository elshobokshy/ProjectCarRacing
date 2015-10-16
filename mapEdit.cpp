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
	Action::Action()
	{
		placeUnplace = false;
		rotation = RoadBlock::standard;
		rtype = RoadBlock::straight;
	}


	void getEvents(sf::RenderWindow &window, Action &action)
	{
		//reset the actions
		action.placeUnplace = false;

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
						case sf::Keyboard::Space:
							action.placeUnplace = true;
						default:
							break;
					}
					break;
				case sf::Event::KeyReleased:
					break;
				case sf::Event::MouseButtonPressed:
					switch(event.mouseButton.button)
					{
						case sf::Mouse::Right:
							action.rotation++;
							break;
						case sf::Mouse::Left:
							action.rotation--;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}	
	}




	void mapEdit(sf::RenderWindow &window)
	{
		RoadBlock cursorBlock(RoadBlock::straight, RoadBlock::standard, sf::Vector2f(200, 200)); //block that will be drawn under the cusor, for the user to know what he is going to use


		Map editedMap; //map that will contain all that will be saved
		Action action;	

	
		while(true)
		{
			mapEdit::getEvents(window, action);
			
			sf::Vector2i cursorBlockPosition = sf::Mouse::getPosition(window); //get the position, relative to the window
			cursorBlock.setPosition( float(cursorBlockPosition.x), float(cursorBlockPosition.y) );



			
			if(action.placeUnplace)
			{
				editedMap.push_back(RoadBlock(action.rtype, action.rotation, sf::Vector2f(0, 0) /*TODO*/));
				std::cout<< static_cast<int>(action.rtype)<< " ; "<< static_cast<int>(action.rotation)<< '\n';
			}

			

		
			window.clear(sf::Color::Black);
			//game display
			window.draw(cursorBlock);

			window.display();
		}
	
	}


}







