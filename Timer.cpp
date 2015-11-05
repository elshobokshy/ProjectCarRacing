#include "Timer.hpp"



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
	sf::Time currentTime(programClock.getElapsedTime());
	if(currentTime - m_startingTimeShift >= m_duration)
	{
		restart();
		return true;
	}
	return false;
}


sf::Time Timer::getFullWaitedDuration()
{
	return programClock.getElapsedTime() - m_oldTime;
}



sf::Time Timer::getExceededDuration()
{
	return programClock.getElapsedTime() - m_oldTime - m_duration;
}



void Timer::restart()
{
	m_oldTime = m_startingTimeShift;
	m_startingTimeShift = programClock.getElapsedTime();
}



