/*
* A RoadBox is the RoadBlock's hit box.
* It's meant to easy collisions with the cars.
*/
#ifndef DEF_ROADBOX_HPP
#define DEF_ROADBOX_HPP

#include <SFML/Graphics/Transformable.hpp>
#include "collision.hpp"
//#include "RoadBlock.hpp"

#include <vector>


class RoadBlock;


class RoadBox: public sf::Transformable //be careful with SFML transformations, none shall be used from a outside
{
	public:
		RoadBox(const RoadBlock &roadBlock);

		const std::vector<collision::LineHitBox> & getLineArray() const;
	
		/*
		These variables are initialized on program start.
		They represent the different standard hitBoxes of RoadBlocks.
		*/
		static const std::vector<collision::LineHitBox> bigArcHitBox;
		static const std::vector<collision::LineHitBox> smallArcHitBox;
		static const std::vector<collision::LineHitBox> straightHitBox;

	private:
		std::vector<collision::LineHitBox> m_hitBox;
		
};





#endif //DEF_ROADBOX_HPP
