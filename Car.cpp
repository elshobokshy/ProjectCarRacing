#include "Car.hpp"


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


Car::Car(sf::Texture &tex, unsigned int speed, unsigned int acceleration)
{
	m_speed = speed;
	m_acceleration = acceleration;
	m_sprite.setTexture(tex);

	sf::Vector2u texSize(tex.getSize());
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	//m_hitBox.setType(collision::hitBox::type);
}



void Car::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_sprite, states);
}
