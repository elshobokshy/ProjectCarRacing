#include "OpenFileError.hpp"


OpenFileError::OpenFileError()
{
}


OpenFileError::~OpenFileError()
{
}


const char* OpenFileError::what() const
{
	return "Error : Cannot open the file\n";
}
