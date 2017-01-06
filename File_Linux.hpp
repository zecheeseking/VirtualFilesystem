#include "File.h"
#include <string>

File::File(const std::string & physicalPath) :
	mPhysicalPath(physicalPath),
	m_pFile(nullptr)
{
}

File::~File(){}

bool File::Open(FileMode mode)
{
	return false;
}

size_t File::Read(uint8_t * buffer, size_t length)
{
	//Copies to a different buffer
	return size_t();
}

size_t File::Write(const uint8_t * buffer, size_t length)
{
	//Copies from a different buffer
	return size_t();
}

std::string File::GetByteIndex()
{
	return std::string();
}

void File::Close()
{

}
