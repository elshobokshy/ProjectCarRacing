#include "Car.hpp"


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cmath>
#include <iostream>

#include "Map.hpp"
#include "collision.hpp"


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


void Car::apply_physics(Map &map)
{
	if(m_physicTimer.ticked())
	{
		//float currentSpeed = norm(m_speedVector);

		sf::Transformable::rotate(m_rotation/**(currentSpeed / m_maxSpeed)*/);
		float rotation = getRotation();
		float accelFactor = m_physicTimer.getFullWaitedDuration().asSeconds();

		//calculate the new speed with the acceleration
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


		//collisions tests
		bool collided = false;
		int i = 0;
		collision::LineHitBox lineBox;
		for(Map::iterator it = map.begin(); it != map.end() && !collided; it++)
		{	
			collided = collision::collision(getHitBox(), it->getHitBox(), lineBox);
		}
		if(collided)
		{
			move(-posOffset); //return to position before collision
			posOffset = collision::bounceVector(
			posOffset
			,collision::normale(lineBox, getPosition())
			);

			move(posOffset);
			setRotation(angle(posOffset));
			std::cout<< getPosition().x<< " ; "<< getPosition().y<< '\n';
		}


		m_acceleration = 0;
		m_physicTimer.restart();

	}
}





float Car::norm(const sf::Vector2f &v) const
{
	return std::sqrt((v.y*v.y) + (v.x*v.x));
}



float Car::angle(const sf::Vector2f &v) const
{
	float signY = v.y >= 0 ? 1 : -1;

	float arcTan = std::atan(v.y / v.x >= 0 ? v.y/v.x : -v.y/v.x);

	float addPi = v.x < 0 ? M_PI/2. : 0;

	float ans = signY * (arcTan + addPi);

	return ans * 180/M_PI;
}




collision::CircleHitBox Car::getHitBox() const
{
	return collision::CircleHitBox(getPosition(), m_hitBoxRadius);
}





