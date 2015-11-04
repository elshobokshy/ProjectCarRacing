/**
* A Car shall be drawable and transformable. It can collide with other objects.
**/
#ifndef DEF_CAR_HPP
#define DEF_CAR_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace sf
{
	class Texture;
}



const unsigned int DEFAULT_CAR_ACCELERATION = 1;



class Car : public sf::Drawable, public sf::Transformable
{
	public:
		Car(sf::Texture &tex, unsigned int speed = 0, int acceleration = 0);


		void accelerate(int accel);

		void apply_physics();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		unsigned int m_speed;
		int m_acceleration;
		sf::Sprite m_sprite;

		//HitBox m_hitBox;

		sf::Vector2f m_speedVector;

		//Constants
		sf::Vector2f dimension;
};



#endif
