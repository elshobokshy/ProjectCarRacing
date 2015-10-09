#include "Map.hpp"
#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include "RoadBlock.hpp"


Map::Map()
{
}


Map::Map(const std::string &fileName)
{
    loadFromFile(fileName)
}


void loadFromFile(const std::string &fileName)
{
	fstream fichier("file.txt", ios::in);

        if(fichier)
        {
            while(true)
            {
                int rotation, rtype;
                float x, y;

                fichier >> rotation >> rtype >> x >> y;

                if(fichier.eof())
                {
                    break; //We stop the loop if we reach the end of the file
                }

                RoadBlock readFile(rtype, rotation, sf::Vector2f(x, y) );
                m_BlockList.push_back(readFile);
            }
        }
        else
            std::cerr << "Error 404 :: Impossible d'ouvrir le fichier !" << std::endl;
}


void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(std::list<RoadBlock>::iterator it=m_BlockList.begin();it != m_BlockList.end(); it++)
    {
        target.draw(*it, states);
    }
}

