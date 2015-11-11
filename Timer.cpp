#include "Timer.hpp"

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




sf::Time Timer::globalTime()
{
	return programClock.getElapsedTime();
}




