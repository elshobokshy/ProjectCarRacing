/*
* Definitions of all that are related to collisions:
* -hitBox
* -repulsions
*/
#ifndef DEF_COLLISION_HPP
#define DEF_COLLISION_HPP


#include <SFML/Graphics/Rect.hpp>


namespace collision
{
	class RectHitBox
	{
		public:
			RectHitBox();
			RectHitBox(const sf::FloatRect &rect1, float orient1);

		
			sf::FloatRect rect;
			float orientation;

	};



	class LineHitBox
	{
		public:
			LineHitBox();
			LineHitBox(const sf::Vector2f &point1, const sf::Vector2f &point2);

		
			sf::Vector2f p1;
			sf::Vector2f p2;
	};

	class CercleHitBox
	{
		public:
			CercleHitBox();
			CercleHitBox(const sf::Vector2f &point, float &rayon);
			
			sf::Vector2f p;
			float rayon;
			
	};

	//TODO
	bool collision(const RectHitBox &rectBox1, const RectHitBox &rectBox2);
	bool collision(const RectHitBox &rectBox, const LineHitBox &lineBox);
	bool collision(const CercleHitBox &cercleBox, const LineHitBox &lineBox);
	bool collision(const sf::Vector2f &point, const CercleHitBox &cercleBox);
	bool collision(const CercleHitBox &cercleBox1, const CercleHitBox &cercleBox2);
}

#endif
