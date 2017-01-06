#include "File.h"
#include <string>

//WINDOWS SPECIFIC IMPLEMENTATION

File::File(const std::string & physicalPath) :
	mPhysicalPath(physicalPath),
	m_pFile(nullptr)
{
}

File::~File(){}

bool File::Open(FileMode mode)
{
	//Check if file can be opened, cache into a buffer and set flags.
	if(mode == FileMode::Read)
		m_pFile = fopen(mPhysicalPath.c_str(), "rb");
	else if(mode == FileMode::Write)
		m_pFile = fopen(mPhysicalPath.c_str(), "wb");

	if(m_pFile == nullptr)
		return false;

	return true;
}

size_t File::Read(uint8_t * buffer, size_t length)
{
	//Copies to a different buffer
	return fread(buffer, sizeof(*buffer), length, m_pFile);
}

size_t File::Write(const uint8_t * buffer, size_t length)
{
	//Copies from a different buffer
	return fwrite(buffer, sizeof(*buffer), length, m_pFile);
}

std::string File::GetByteIndex()
{
	return std::string();
}

void File::Close()
{
	//Empty buffer
	if (m_pFile)
		fclose(m_pFile);
}
