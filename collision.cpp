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
		p2 = p1;0
	}


	LineHitBox::LineHitBox(const sf::Vector2f &point1, const sf::Vector2f &point2)
	{
		p1 = point1;
		p2 = point2;
	}
	
	CercleHitBox::CercleHitBox()
	{
		p = sf::Vector2f(0,0);
		rayon = 1;
	}
	
	CercleHitBox::CercleHitBox(const sf::Vector2f &point, float rayon1)
	{
		p = point;
		rayon = rayon1;
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
	
	bool collision(const sf::Vector2f &point, const CercleHitBox &cercleBox)
	{
		sf::Vector2f C(cercleBox.p);
		float x = point.x, y = point.y;
		float rayon = cercleBox.rayon;
		
		float d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
		if (d2>rayon*rayon)
			return false;
		else
			return true;
	}
	
	bool collision(const CercleHitBox &cercleBox, const LineHitBox &lineBox)
	{
		sf::Vector2f A(lineBox.p1), B(lineBox.p2), C(cercleBox.p);
		
		sf::Vector2f AB,AC,BC;
		AB.x = B.x - A.x;
	    AB.y = B.y - A.y;
	    AC.x = C.x - A.x;
	    AC.y = C.y - A.y;
	    BC.x = C.x - B.x;
	    BC.y = C.y - B.y;
	    float pscal1 = AB.x*AC.x + AB.y*AC.y;  // produit scalaire
	    float pscal2 = (-AB.x)*BC.x + (-AB.y)*BC.y;  // produit scalaire
	    if (pscal1>=0 && pscal2>=0)
			return true;   // I entre A et B, ok.
	    // dernière possibilité, A ou B dans le cercle
	    if (collision(A,cercleBox))
		  return true;
	    if (collision(B,cercleBox))
		  return true;
	    return false;
	}
	
	bool collision(const CercleHitBox &cercleBox1, const CercleHitBox &cercleBox2)
	{
		sf::Vector2f C1(cercleBox1.p), C2(cercleBox2.p);
		float d2 = (C1.x-C2.x)*(C1.x-C2.x) + (C1.y-C2.y)*(C1.y-C2.y);
		if (d2 > (cercleBox1.rayon + cercleBox2.rayon)*(cercleBox1.rayon + cercleBox2.rayon))
			return false;
		else
			return true;
	}


}
