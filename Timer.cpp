#include "Timer.hpp"

#include <SFML/System/Sleep.hpp>

#include <iostream>


sf::Clock Timer::programClock;




Timer::Timer()
{
}


Timer::Timer(const sf::Time &duration): m_duration(duration)
{
}



void Timer::setDuration(const sf::Time &duration)
{
	m_duration = duration;
}


sf::Time Timer::getDuration() const
{
	return m_duration;
}



bool Timer::ticked()
{
	sf::Time currentTime(globalTime());
	if(currentTime - m_startingTimeShift >= m_duration)
	{
		//std::cout<< "tic\n";
		return true;
	}
	return false;
}


sf::Time Timer::getFullWaitedDuration() const
{
	return globalTime() - m_oldTime;
}



sf::Time Timer::getExceededDuration() const
{
	return globalTime() - m_oldTime - m_duration;
}



void Timer::restart()
{
	sf::Time currentTime(globalTime());
	m_oldTime = currentTime - getExceededDuration();
	m_startingTimeShift = m_oldTime;
}





void Timer::autoSleep()
{
	while(!ticked())
	{
		sf::Time currentTime(globalTime());
		//std::cout<< (m_oldTime + m_duration - currentTime).asSeconds()<< '\n';
		sf::sleep(m_oldTime + m_duration - currentTime);
	}
	restart();
}





sf::Time Timer::globalTime()
{
	return programClock.getElapsedTime();
}




