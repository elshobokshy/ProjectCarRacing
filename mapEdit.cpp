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
					window.close();
					break;
				case sf::Event::KeyPressed:
					switch(event.key.code)
					{
						case sf::Keyboard::Escape:
							window.close();
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
							action.rtype++;
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

	
		while(window.isOpen())
		{
			//RoadBlock block(action.rtype, action.rotation, sf::Vector2f(0, 0));



			mapEdit::getEvents(window, action);
			
			sf::Vector2i cursorBlockPosition = sf::Mouse::getPosition(window); //get the position, relative to the window
			cursorBlock.setPosition( float(cursorBlockPosition.x), float(cursorBlockPosition.y) );
			cursorBlock.setRotation(action.rotation);
			cursorBlock.setType(action.rtype);



			
			if(action.placeUnplace)
			{
				//determine the size position of the block to be placed
				sf::Vector2f posNewBlock((int(cursorBlockPosition.x) / 256) * 256, (int(cursorBlockPosition.y) / 256) * 256);

				editedMap.push_back(RoadBlock(action.rtype, action.rotation, posNewBlock));
				//std::cout<< static_cast<int>(action.rtype)<< " ; "<< static_cast<int>(action.rotation)<< " ; " <<posNewBlock.x<< " / "<< posNewBlock.y<< '\n';
			}

			

		
			window.clear(sf::Color::Black);
			//game display
			window.draw(editedMap);
			window.draw(cursorBlock);

			window.display();
		}

		//finally : save to file !
		editedMap.saveToFile("saveMap.pwet");
	}
}







