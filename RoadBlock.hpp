#ifndef DEF_ROADBLOCK_HPP	
#define DEF_ROADBLOCK_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>


#include <string>


const std::string STRAIGHT_TEXTURE_NAME("gameData/images/straight.png");
const std::string CORNER_TEXTURE_NAME("gameData/images/corner.png");


class RoadBlock : public sf::Drawable, public sf::Transformable
{
	enum type
	{
		straight, corner
	}

	enum rotation //clockwise
	{
		standard, right, left, down
	}

	public:
		RoadBlock();
		RoadBlock(const sf::Texture &texture, type t, rotation r);
		RoadBlock(type t, rotation r);



		void setRotation(rotation r);
		void setType(type t);



		static const sf::Texture straightTexture(STRAIGHT_TEXTURE_NAME);
		static const sf::Texture cornerTexture(CORNER_TEXTURE_NAME);

		
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		sf::Sprite m_sprite;
		type m_type;
}



#endif
