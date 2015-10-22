#include "collision.hpp"


namespace collision
{


	RectHitBox::RectHitBox()
	{
		orientation = 0;
	}


	RectHitBox::RectHitBox(const sf::FloatRect &rect1, float orient1)
	{
		rect = rect1;
		orientation = orient1;
	}



	LineHitBox::LineHitBox()
	{
		p1 = sf::Vector2f(0, 0);
		p2 = p1;
	}


	LineHitBox::LineHitBox(const sf::Vector2f &point1, const sf::Vector2f &point2)
	{
		p1 = point1;
		p2 = point2;
	}
	
	bool collision(const RectHitBox &rectBox1, const RectHitBox &rectBox2)
	{
		sf::FloatRect rect1 = rectBox1.rect, rect2 = rectBox2.rect;
		
		/*int centre1_x = rect1.left + rect1.width/ 2;
		int centre1_y = rect1.top + rect1.height/ 2;
		int centre2_x = rect2.left + rect2.width/ 2;
		int centre2_y = rect2.top + rect2.height/ 2;*/
		
		int dis2centre = (rect1.left-rect2.left)*(rect1.left-rect2.left) + (rect1.top-rect2.top)*(rect1.top-rect2.top); //Distance entre deux centre
		
		int rayon1 = ((rect1.height * rect1.height) + (rect1.width * rect1.width))/2;
		int rayon2 = ((rect2.height * rect2.height) + (rect2.width * rect2.width))/2;
		return (dis2centre < (rayon1 + rayon2)*(rayon1 + rayon2));
	}


}
