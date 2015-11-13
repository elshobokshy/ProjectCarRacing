#include "RoadBlock.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include "FileLoader.hpp"
#include "collision.hpp"

#include <iostream>


const sf::Texture RoadBlock::straightTexture = createFromFile<sf::Texture>(STRAIGHT_TEXTURE_NAME);
const sf::Texture RoadBlock::cornerTexture = createFromFile<sf::Texture>(CORNER_TEXTURE_NAME);
const sf::Texture RoadBlock::grassTexture = createFromFile<sf::Texture>(GRASS_TEXTURE_NAME);


const sf::Vector2i RoadBlock::texSize = sf::Vector2i(256, 256);

static const std::vector<collision::LineHitBox> bigArcHitBox = getBigArcHitBox();
static const std::vector<collision::LineHitBox> smallArcHitBox = getSmallArcHitBox();
static const std::vector<collision::LineHitBox> straightHitBox = getStraightHitBox();



RoadBlock::RoadBlock()
{
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
}




RoadBlock::RoadBlock(const sf::Texture &texture, roadType t, rotation r, const sf::Vector2f &pos)
{
	setPosition(pos);

	m_sprite.setTexture(texture);
	setType(t);
	
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);
	
	setRotation(r);

	m_sprite.setOrigin(0, 0);
}




RoadBlock::RoadBlock(roadType t, rotation r, const sf::Vector2f &pos)
{
	m_sprite.setOrigin(float(texSize.x)/2.f, float(texSize.y)/2.f);

	setPosition(pos);

	//std::cout<< pos.x<< " ; "<< pos.y<< '\n';

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
		case standard:
			m_sprite.setRotation(0);
			break;
		default:
			break;
	}
	//m_sprite.rotate(10);
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
	std::cout<< r<< '\n';
	switch(int(r))
	{
		case 90:
			return right;
			break;
		case 270:
			return left;
			break;
		case 180:
			return down;
			break;
		default:
			break;
	}
	return standard; //only to dodge a warning
}



RoadBlock::roadType RoadBlock::getRType()
{
	return m_type;
}



/*sf::Vector2f RoadBlock::getPosition()
{
	return m_sprite.getPosition();
}*/




void RoadBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.transform.translate(float(texSize.x)/2.f, float(texSize.y)/2.f);

	target.draw(m_sprite, states);
}




RoadBlock::rotation operator++(RoadBlock::rotation &r, int nn)
{
	RoadBlock::rotation ans(r); //answer
	switch(r)
	{
		case RoadBlock::standard:
			r = RoadBlock::right;
			break;
		case RoadBlock::right:
			r = RoadBlock::down;
			break;
		case RoadBlock::down:
			r = RoadBlock::left;
			break;
		case RoadBlock::left:
			r = RoadBlock::standard;
			break;
		default:
			break;
	}
	return ans;
}





RoadBlock::rotation operator--(RoadBlock::rotation &r, int nn)
{
	RoadBlock::rotation ans(r); //answer
	switch(r)
	{
		case RoadBlock::standard:
			r = RoadBlock::left;
			break;
		case RoadBlock::right:
			r = RoadBlock::standard;
			break;
		case RoadBlock::down:
			r = RoadBlock::right;
			break;
		case RoadBlock::left:
			r = RoadBlock::down;
			break;
		default:
			break;
	}
	return ans;
}




RoadBlock::roadType operator++(RoadBlock::roadType &r, int)
{
	RoadBlock::roadType ans(r);
	switch(r)
	{
		case RoadBlock::straight:
			r = RoadBlock::corner;
			break;
		case RoadBlock::corner:
			r = RoadBlock::straight;
			break;
		default:
			break;
	}
	return ans;
}



std::vector<collision::LineHitBox> getBigArcHitBox()
{
	using namespace collision;

	std::vector<LineHitBox> hitBox(3);
	hitBox[0] = LineHitBox(sf::Vector2f(31, 256), sf::Vector2f(31, 134));
	hitBox[1] = LineHitBox(sf::Vector2f(31, 134), sf::Vector2f(121, 32));
	hitBox[2] = LineHitBox(sf::Vector2f(121, 32), sf::Vector2f(256, 31));
	return hitBox;
}


std::vector<collision::LineHitBox> getSmallArcHitBox()
{
	using namespace collision;

	std::vector<LineHitBox> hitBox(2);
	hitBox[0] = LineHitBox(sf::Vector2f(225, 255), sf::Vector2f(226, 224));
	hitBox[1] = LineHitBox(sf::Vector2f(226, 224), sf::Vector2f(256, 225));
	return hitBox;
}



std::vector<collision::LineHitBox> getStraightHitBox()
{
	using namespace collision;

	std::vector<LineHitBox> hitBox(2);
	hitBox[0] = LineHitBox(sf::Vector2f(31, 256), sf::Vector2f(31, 0));
	hitBox[1] = LineHitBox(sf::Vector2f(225, 256), sf::Vector2f(225, 0));
	return hitBox;
}


