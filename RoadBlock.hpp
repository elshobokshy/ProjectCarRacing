#ifndef DEF_ROADBLOCK_HPP	
#define DEF_ROADBLOCK_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <string>

namespace sf
{
	class RenderTarget;
}


static const std::string STRAIGHT_TEXTURE_NAME("gameData/images/straight.png");
static const std::string CORNER_TEXTURE_NAME("gameData/images/corner.png");
static const std::string GRASS_TEXTURE_NAME("gameData/images/grass2.png");


class RoadBlock : public sf::Drawable, public sf::Transformable
{
	public:
		enum roadType
		{
			straight, corner
		};

		enum rotation //clockwise
		{
			standard, right, left, down
		};

	
		RoadBlock();
		RoadBlock(const sf::Texture &texture, roadType t, rotation r, const sf::Vector2f &pos);
		RoadBlock(roadType t, rotation r, const sf::Vector2f &pos = sf::Vector2f(0.0, 0.0));
		rotation getRotation();
		roadType getRType()
		getPosition();

		void setRotation(rotation r);
		void setType(roadType t);


		//standard shared textures
		static const sf::Texture straightTexture;
		static const sf::Texture cornerTexture;
		static const sf::Texture grassTexture;
		
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		sf::Sprite m_sprite;
		roadType m_type;
};


RoadBlock::rotation operator++(RoadBlock::rotation &r, 0);
RoadBlock::rotation operator--(RoadBlock::rotation &r, 0);



#endif
