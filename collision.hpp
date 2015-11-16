/*
* Definitions of all that are related to collisions:
* -hitBox
* -repulsions
*/
#ifndef DEF_COLLISION_HPP
#define DEF_COLLISION_HPP


#include <SFML/Graphics/Rect.hpp>
//#include "RoadBox.hpp"

class RoadBox;


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
			
			void move(const sf::Vector2f &point2);
		
			sf::Vector2f p1;
			sf::Vector2f p2;
	};

	class CircleHitBox
	{
		public:
			CircleHitBox();
			CircleHitBox(const sf::Vector2f &point, float rayon1);
			
			sf::Vector2f p;
			float rayon;
			
	};

	bool collision(const RectHitBox &rectBox1, const RectHitBox &rectBox2);
	bool collision(const RectHitBox &rectBox, const LineHitBox &lineBox);
	bool collisionAsInfiniteLine(const CircleHitBox &cercleBox, const LineHitBox &lineBox);

	//circle and segment
	bool collision(const CircleHitBox &cercleBox, const LineHitBox &lineBox);
	bool collision(const sf::Vector2f &point, const CircleHitBox &cercleBox);
	bool collision(const CircleHitBox &cercleBox1, const CircleHitBox &cercleBox2);

	bool collision(const CircleHitBox &circleBox, const RoadBox &roadBox);


} //namespace collision



#endif
