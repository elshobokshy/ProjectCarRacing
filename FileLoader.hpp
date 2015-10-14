#ifndef DEF_FILELOADER_HPP
#define DEF_FILELOADER_HPP

#include <string>


//create an empty object, use the loadFromfile method, and return it
template <typename T>
T createFromFile(const std::string &file);


#include "FileLoader.tpp"


#endif
