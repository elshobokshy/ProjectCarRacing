#include "Map.hpp"
#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include "RoadBlock.hpp"

#include <iostream>
#include <fstream>

Map::Map()
{
}


Map::Map(const std::string &fileName)
{
    loadFromFile(fileName);
}


void Map::loadFromFile(const std::string &fileName)
{
	std::ifstream fichier("file.txt", std::ios::in);

        if(fichier)
        {
            while(true)
            {
                int rotation;
		int rtype;
                float x, y;

                fichier >> rotation >> rtype >> x >> y;


                if(fichier.eof())
                {
                    break; //We stop the loop if we reach the end of the file
                }

                RoadBlock readFile(static_cast<RoadBlock::roadType>(rtype), static_cast<RoadBlock::rotation>(rotation), sf::Vector2f(x, y) );
                m_BlockList.push_back(readFile);
            }
        }
        else
            std::cerr << "Error 404 :: Impossible d'ouvrir le fichier !" << std::endl;
}

void Map::saveToFile(const std::string &fileName)
{
	std::ofstream fichier("file.txt", std::ios::out);

        if(fichier)
        {
            	for(std::list<RoadBlock>::iterator it=m_BlockList.begin();it != m_BlockList.end(); it++)
		{
                float x, y;

		sf::Vector2f pos(it->getPosition());
		x = pos.x;
		y = pos.y;
				
                fichier << static_cast<RoadBlock::rotation>(it->getRotation()) << static_cast<RoadBlock::roadType>(it->getRType()) << x << y;
            }
        }
        else
            std::cerr << "Error 404 :: Impossible de sauvegarder le fichier !" << std::endl;
}





void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(std::list<RoadBlock>::const_iterator it=m_BlockList.begin(); it != m_BlockList.end(); it++)
    {
        target.draw(*it, states);
    }
}



void Map::push_back(const RoadBlock &RdBk)
{
	m_BlockList.push_back(RdBk);
}
