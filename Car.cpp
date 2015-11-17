#include "Car.hpp"


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cmath>
#include <iostream>




Car::Car(sf::Texture &tex, float maxSpeed)
{
	m_acceleration = 0;
	m_rotation = 0;

	m_sprite.setTexture(tex);

	sf::Vector2u texSize(tex.getSize());
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	//m_speedVector = sf::Vector2f(0, 0);

	//to take the included circle, take the min btw width and height
	m_hitBoxRadius = 93/2;

	m_maxSpeed = maxSpeed;

	m_physicTimer.setDuration(sf::seconds(1./60.)); //60 fps
	m_physicTimer.restart();

}



void Car::accelerate(float accel)
{
	m_acceleration = accel;
}




void Car::rotate(float rot)
{
	m_rotation = rot;
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
		//float currentSpeed = norm(m_speedVector);

		sf::Transformable::rotate(m_rotation/**(currentSpeed / m_maxSpeed)*/);
		float rotation = getRotation();

		float accelFactor = m_physicTimer.getFullWaitedDuration().asSeconds();

		//std::cout<< accelFactor * 60<< "\n";

		//calculate the new speed with the acceleration
		/*m_speedVector.x += std::cos(rotation*M_PI/180)*m_acceleration*accelFactor;
		m_speedVector.y += std::sin(rotation*M_PI/180)*m_acceleration*accelFactor;*/
		m_speed += accelFactor*m_acceleration;
		if(m_speed > m_maxSpeed)
		{
			m_speed = m_maxSpeed;
			//std::cout<< "max attained\n";
		}
		else if(m_speed < -m_maxSpeed)
		{
			m_speed = -m_maxSpeed;
			//std::cout<< "min attained\n";
		}

		sf::Vector2f posOffset(
		m_speed*accelFactor*std::cos(rotation*M_PI/180)
		, m_speed*accelFactor*std::sin(rotation*M_PI/180)
		);

		//calculate the new position with the speed
		move(posOffset);


		m_acceleration = 0;
		m_physicTimer.restart();

		//std::cout<< getPosition().x<< " ; "<< getPosition().y<< '\n';
		//std::cout<< 60*accelFactor<< '\n';
	}
}





float Car::norm(const sf::Vector2f &v) const
{
	return std::sqrt((v.y*v.y) + (v.x*v.x));
}




collision::CircleHitBox Car::getHitBox() const
{
	return collision::CircleHitBox(getPosition(), m_hitBoxRadius);
}





