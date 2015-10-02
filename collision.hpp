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
			RectHitBox(const sf::FloatRect &rect, float orientation);

		
			sf::FloatRect m_rect;
			float m_orientation;

	};



	class LineHitBox
	{
		public:
			LineHitBox();
			LineHitBox(const sf::Vector2f &p1, const sf::Vector2f &p2);

		
			sf::Vector2f m_p1;
			sf::Vector2f m_p2;
	};


	//TODO
	bool collision(const RectHitBox &rectBox1, const RectHitBox &rectBox2);
	bool collision(const RectHitBox &rectBox, const LineHitBox &lineBox);


/*
class HitBox
{
	enum type
	{
		rect, line
	}

	
	union borderInfo
	{
		//Rectangle
		sf::FloatRect 

	}

	public:
		HitBox();
		HitBox(type t);

	private:
		type m_type;

};*/

}

#endif
