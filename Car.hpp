/**
* A Car shall be drawable and transformable. It can collide with other objects.
**/
#ifndef DEF_CAR_HPP
#define DEF_CAR_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Timer.hpp"


namespace sf
{
	class Texture;
}



const unsigned int DEFAULT_CAR_ACCELERATION = 1;



class Car : public sf::Drawable, public sf::Transformable
{
	public:
		Car(sf::Texture &tex, float maxSpeed = 100);


		void accelerate(float accel);

		void rotate(float rot);

		void apply_physics();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		float norm(const sf::Vector2f &v) const;
	


		float m_acceleration;
		float m_rotation;

		sf::Sprite m_sprite;

		Timer m_physicTimer; //timer that permit the physics to apply at every frame

		sf::Vector2f m_speedVector;
		float m_maxSpeed;

		//Constants
		sf::Vector2f dimension;
};



#endif
