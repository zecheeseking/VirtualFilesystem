#include "File.h"
#include <string>

//WINDOWS SPECIFIC IMPLEMENTATION

File::File(const std::string & physicalPath) :
	mPhysicalPath(physicalPath)
{
}

File::~File(){}

bool File::Open(FileMode mode)
{
	//Chek if file can be opened, cache into a buffer and set flags.

	return false;
}

size_t File::Read(uint8_t *, size_t)
{
	//Copies to a different buffer
	return size_t();
}

size_t File::Write(const uint8_t *, size_t)
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
