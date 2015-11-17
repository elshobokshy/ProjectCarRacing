#ifndef DEF_ROADBLOCK_HPP	
#define DEF_ROADBLOCK_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <string>
#include <vector>

#include "collision.hpp"
#include "RoadBox.hpp"

namespace sf
{
	class RenderTarget;
}


static const std::string STRAIGHT_TEXTURE_NAME("gameData/images/straight.png");
static const std::string CORNER_TEXTURE_NAME("gameData/images/corner1.png");
static const std::string GRASS_TEXTURE_NAME("gameData/images/grass2.png");


class RoadBlock : public sf::Drawable, public sf::Transformable
{
	public:
		enum roadType
		{
			straight = 0, 
			corner = 1
		};

		enum rotation //clockwise
		{
			standard = 0, 
			right= 1, 
			left = 2, 
			down = 3
		};

	
		RoadBlock();
		RoadBlock(const sf::Texture &texture, roadType t, rotation r, const sf::Vector2f &pos);
		RoadBlock(roadType t, rotation r, const sf::Vector2f &pos = sf::Vector2f(0.0, 0.0));

		rotation getRotation() const;
		roadType getRType() const;
	
		float getRotationAsDegrees() const;
		
		void setRotation(rotation r);
		void setType(roadType t);


		RoadBox getHitBox() const;


		//standard shared textures
		static const sf::Texture straightTexture;
		static const sf::Texture cornerTexture;
		static const sf::Texture grassTexture;

		//standard shared textures size
		static const sf::Vector2i texSize;

		
	protected:	
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::Sprite m_sprite;
		roadType m_type;
};



//turn 90° clockwise
RoadBlock::rotation operator++(RoadBlock::rotation &r, int);

//turn -90° clockwise
RoadBlock::rotation operator--(RoadBlock::rotation &r, int);


//change of roadType to the next one
RoadBlock::roadType operator++(RoadBlock::roadType &r, int);




#endif
