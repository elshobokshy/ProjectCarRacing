#include "mapEdit.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/View.hpp>

#include "RoadBlock.hpp"
#include "Map.hpp"
#include "Timer.hpp"

#include <iostream>




namespace mapEdit
{
	Action::Action()
	{
		placeUnplace = false;
		rotation = RoadBlock::standard;
		rtype = RoadBlock::straight;
		viewMove = sf::Vector2f(0, 0);
	}


	void getEvents(sf::RenderWindow &window, Action &action)
	{
		//reset the actions
		action.placeUnplace = false;
		action.viewMove = sf::Vector2f(0, 0);

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

		//speeds in px per second
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			action.viewMove = sf::Vector2f(0, 512);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			action.viewMove = sf::Vector2f(0, -512);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			action.viewMove = sf::Vector2f(512, 0);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			action.viewMove = sf::Vector2f(-512, 0);
		}

	}




	void mapEdit(sf::RenderWindow &window)
	{
		sf::View mapView(sf::FloatRect(0, 0, 800, 600));
		window.setView(mapView);

		RoadBlock cursorBlock(RoadBlock::straight, RoadBlock::standard, sf::Vector2f(200, 200)); //block that will be drawn under the cusor, for the user to know what he is going to use


		Map editedMap; //map that will contain all that will be saved
		Action action;	

		Timer loopTimer(sf::seconds(1./60.)); //60 fps

		//timer that is useful to calculate a time factor
		Timer timerFactorTimer; //no duration time is needed 
	
		while(window.isOpen())
		{
			//RoadBlock block(action.rtype, action.rotation, sf::Vector2f(0, 0));



			mapEdit::getEvents(window, action);
			
			sf::Vector2i cursorBlockPosition = sf::Mouse::getPosition(window); //get the position, relative to the window
			cursorBlock.setPosition( window.mapPixelToCoords(cursorBlockPosition) );
			//cursorBlock.setPosition( window.mapPixelToCoords(sf::Mouse::getPosition(window)) );
			std::cout<< window.mapPixelToCoords(sf::Mouse::getPosition(window)).x << " ; "<< window.mapPixelToCoords(sf::Mouse::getPosition(window)).y<< '\n';
			cursorBlock.setRotation(action.rotation);
			cursorBlock.setType(action.rtype);



			
			if(action.placeUnplace)
			{
				//determine the size position of the block to be placedi
				int signX = 1, signY = 1;
				if(cursorBlock.getPosition().x < 0)
				{
					signX = -1;
				}
				if(cursorBlock.getPosition().y < 0)
				{
					signY = -1;
				}
				sf::Vector2f posNewBlock((int(cursorBlock.getPosition().x) / 256) * 256, (int(cursorBlock.getPosition().y) / 256) * 256);
				if(cursorBlock.getPosition().x < 0)
				{
					posNewBlock.x -= 256;
				}
				if(cursorBlock.getPosition().y < 0)
				{
					posNewBlock.y -= 256;
				}

				//sf::Vector2f posNewBlock();


				editedMap.push_back(RoadBlock(action.rtype, action.rotation, posNewBlock));
				//std::cout<< static_cast<int>(action.rtype)<< " ; "<< static_cast<int>(action.rotation)<< " ; " <<posNewBlock.x<< " / "<< posNewBlock.y<< '\n';
			}

			//calculating the coordinates of the new view
			float viewFactor = timerFactorTimer.swapTime().asSeconds();

		
			//game display
			mapView.move(action.viewMove*viewFactor);
			//std::cout<< viewFactor<< '\n';
			window.setView(mapView);

			window.clear(sf::Color::Black);

			window.draw(editedMap);
			window.draw(cursorBlock);

			window.display();

			//time handling///////////////////////////
			
			loopTimer.autoSleep();

			// \time handling///////////////////////// 
		}

		//finally : save to file !
		editedMap.saveToFile("saveMap.pwet");
	}
}







