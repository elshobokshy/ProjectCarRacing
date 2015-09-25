#include "Car.hpp"


Car::Car(const sf::Texture &tex, unsigned int speed, unsigned int acceleration)
{
	m_speed = speed;
	m_acceleration = acceleration;
	m_sprite.setTexture(tex);

	sf::Vector2u texSize(tex.getSize());
	sprite.setOrigin(float(texSize.x)/2f, float(texSize.y)/2f);
	//m_hitBox.setType(collision::hitBox::type);
}



void Car::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_sprite, states);
}
