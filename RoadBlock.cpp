#include "RoadBlock.hpp"


RoadBlock::RoadBlock()
{
}


RoadBlock::RoadBlock(const sf::Texture &texture, type t, rotation r)
{
	m_sprite.setTexture(texture);
	setType(t);
	
	sf::Vector2u texSize(texture.getSize());
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	
	setRotation(r);
}



RoadBlock::RoadBlock(type t, rotation r)
{
	setRotation(r);
	setType(t);

	sf::Vector2u texSize(texture.getSize());
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
}




void RoadBlock::setRotation(rotation r)
{
	switch(r)
	{
		case right:
			m_sprite.setRotation(90);
			break;
		case left:
			m_sprite.setRotation(-90);
			break;
		case down:
			m_sprite.setRotation(180);
			break;
		default:
			break;
	}
}




void RoadBlock::setType(type t)
{
	m_type = t;

	switch(t)
	{
		case straight:
			m_sprite.setTexture(straightTexture);
			break;
		case corner:
			m_sprite.setTexture(cornerTexture);
			break;
		default:
			break;
	}
}


