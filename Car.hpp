/**
* A Car shall be drawable and transformable. It can collide with other objects.
**/
#ifndef DEF_CAR_HPP
#define DEF_CAR_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprites.hpp>


namespace sf
{
	class Texture;
}


class Car : public sf::Drawable, sf::Transformable
{
	public:
		Car(const sf::Texture &tex, unsigned int speed, unsigned int acceleration);


	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		unsigned int m_speed;
		unsigned int m_acceleration;
		sf::Sprite m_sprite;
		//HitBox m_hitBox;i

		//Constants
		Vector2f dimension;
};



#endif
