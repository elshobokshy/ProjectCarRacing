#include "collision.hpp"


namespace collision
{


	RectHitBox::RectHitBox()
	{
		m_orientation = 0;
	}


	RectHitBox::RectHitBox(const sf::FloatRect &rect, float orientation)
	{
		m_rect = rect;
		m_orientation = orientation;
	}



	LineHitBox::LineHitBox()
	{
		m_p1 = sf::Vector2f(0, 0);
		m_p2 = m_p1;
	}


	LineHitBox::LineHitBox(const sf::Vector2f &p1, const sf::Vector2f &p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}


}
