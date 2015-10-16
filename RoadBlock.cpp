#include "RoadBlock.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include "FileLoader.hpp"



const sf::Texture RoadBlock::straightTexture = createFromFile<sf::Texture>(STRAIGHT_TEXTURE_NAME);
const sf::Texture RoadBlock::cornerTexture = createFromFile<sf::Texture>(CORNER_TEXTURE_NAME);
const sf::Texture RoadBlock::grassTexture = createFromFile<sf::Texture>(GRASS_TEXTURE_NAME);

RoadBlock::RoadBlock()
{
}

RoadBlock::RoadBlock(const sf::Texture &texture, roadType t, rotation r, const sf::Vector2f &pos)
{
	setPosition(pos);

	m_sprite.setTexture(texture);
	setType(t);
	
	sf::Vector2u texSize(texture.getSize());
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	
	setRotation(r);
}

RoadBlock::RoadBlock(roadType t, rotation r, const sf::Vector2f &pos)
{
	setPosition(pos);

	setRotation(r);
	setType(t);
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

void RoadBlock::setType(roadType t)
{
	m_type = t;

	switch(t)
	{
		case straight:
			m_sprite.setTexture(RoadBlock::straightTexture);
			break;
		case corner:
			m_sprite.setTexture(RoadBlock::cornerTexture);
			break;
		default:
			break;
	}
}

RoadBlock::rotation RoadBlock::getRotation()
{
	float r = m_sprite.getRotation();
	switch(r)
	{
		case 90:
			return right;
			break;
		case -90:
			return left;
			break;
		case 180:
			return down;
			break;
		default:
			break;
	}
}

RoadBlock::roadType RoadBlock::getRType()
{
	return m_type;
}

sf::Vector2f Roadblock::getPosition()
{
	return m.sprite.getPosition();
}

void RoadBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_sprite, states);
}
