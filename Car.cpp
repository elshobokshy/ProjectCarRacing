#include "Car.hpp"


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cmath>
#include <iostream>


Car::Car(sf::Texture &tex, unsigned int speed, int acceleration)
{
	m_speed = speed;
	m_acceleration = acceleration;
	m_sprite.setTexture(tex);

	sf::Vector2u texSize(tex.getSize());
	//std::cout<< texSize.x<< " ; "<< texSize.y << "\n";
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	//m_hitBox.setType(collision::hitBox::type);
	m_speedVector = sf::Vector2f(0, 0);
}



void Car::accelerate(int accel)
{
	m_acceleration += accel;
}



void Car::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_sprite, states);
}


void Car::apply_physics()
{
	float rotation = getRotation();
	float facceleration = float(m_acceleration);

	//calculate the new speed with the acceleration
	m_speedVector.x += std::cos(rotation)*facceleration;
	m_speedVector.y += std::sin(rotation)*facceleration;

	//calculate the new position with the speed
	move(m_speedVector);

	std::cout<< facceleration<< " : "<<getPosition().x<< " ; "<< getPosition().y<< '\n';
}






