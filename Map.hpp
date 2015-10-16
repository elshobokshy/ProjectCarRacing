/*
* The map will encapsulate the road blocks, and furthermore ways to load it and some interactions with the cars.
*/
#ifndef DEF_MAP_H
#define DEF_MAP_H


#include <SFML/Graphics/RenderStates.hpp>
#include <list>
#include <fstream>
#include "RoadBlock.hpp"
#include <string>


namespace sf
{
	class RenderTarget;
}

class Map : public sf::Drawable
{
	public:
		Map();
		Map(const std::string &fileName);

		void loadFromFile(const std::string &fileName);
		void saveToFile(const std::string &fileName);
		void push_back(const RoadBlock &RdBk);




		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		std::list<RoadBlock> m_BlockList;

};


#endif
