#ifndef DEF_MAPEDIT_HPP
#define DEF_MAPEDIT_HPP

#include "RoadBlock.hpp"

namespace sf
{
	class RenderWindow;
}


namespace mapEdit
{
	struct Action
	{
		Action();

		bool placeUnplace;
		RoadBlock::rotation rotation;
		RoadBlock::roadType rtype;
		sf::Vector2f viewMove;
	};

	void getEvents(sf::RenderWindow &window, Action &action);


	void mapEdit(sf::RenderWindow &window);
}

#endif 
