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
   int dis2centre = (rectBox1.left-rectBox2.left)*(rectBox1.left-rectBox2.left) + (rectBox1.top-rectBox2.top)*(rectBox1.top-rectBox2.top); //Distance entre deux centre
   int centre1_x = rectBox1.left + rectBox1.width/ 2;
   int centre1_y = rectBox1.top + rectBox1.height/ 2;
   int centre2_x = rectBox2.left + rectBox2.width/ 2;
   int centre2_y = rectBox2.top + rectBox2.height/ 2;
   int rayon1 = ((rectBox1.height * rectBox1.height) + (rectBox1.width * rectBox1.width))/2;
   int rayon2 = ((rectBox2.height * rectBox2.height) + (rectBox2.width * rectBox2.width))/2;
   return (dis2centre < (rayon1 + rayon2)*(rayon1 + rayon2))
	}


}
