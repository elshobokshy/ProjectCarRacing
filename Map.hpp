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


namespace hidden
{
	class MapIterator;
}


class Map : public sf::Drawable
{
	public:
		typedef std::list<RoadBlock>::iterator iterator;

		Map();
		Map(const std::string &fileName);

		void loadFromFile(const std::string &fileName);
		void saveToFile(const std::string &fileName);
		void push_back(const RoadBlock &RdBk);


		Map::iterator begin();
		Map::iterator end();



		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		std::list<RoadBlock> m_BlockList;

};



/*
namespace hidden
{
	class MapIterator
	{
		public:
			MapIterator();

			MapIterator operator++(int);
			MapIterator operator--(int);

			bool atEnd() const;

		private:
			std::list<RoadBlock>::iterator m_listIterator;
	};
}
*/





#endif
