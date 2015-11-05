#include "Car.hpp"


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cmath>
#include <iostream>


Car::Car(sf::Texture &tex, unsigned int speed)
{
	m_acceleration = 0;
	m_sprite.setTexture(tex);

	sf::Vector2u texSize(tex.getSize());
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	m_speedVector = sf::Vector2f(0, 0);

	m_physicTimer.setDuration(sf::seconds(0.0166667/*0x3c888889*/)); //wtf ?!
	m_physicTimer.restart();
}



void Car::accelerate(int accel)
{
	m_acceleration = accel;
}



void Car::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	//states.transform.rotate(-90); //the car is not well orientated in the loaded image
	target.draw(m_sprite, states);
}


void Car::apply_physics()
{
	if(m_physicTimer.ticked())
	{
		float rotation = getRotation();
		float accelFactor = m_physicTimer.getFullWaitedDuration().asSeconds();

		//calculate the new speed with the acceleration
		m_speedVector.x += std::cos(rotation*M_PI/180)*m_acceleration*accelFactor*60;
		m_speedVector.y += std::sin(rotation*M_PI/180)*m_acceleration*accelFactor*60;

		//calculate the new position with the speed
		move(m_speedVector);

		//reset acceleration

		//std::cout<< m_acceleration<< " : "<< m_speedVector.x<< " ; "<< m_speedVector.y<< '\n';

		//std::cout<< rotation<< '\n';


		m_acceleration = 0;
	}
}






