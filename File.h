#pragma once

#include "FileMode.h"
#include <string>
#include <stdint.h>
#include <vector>

class File
{
public:
	File(const std::string & physicalPath);
	virtual ~File();

	bool Open(FileMode mode);
	size_t Read(uint8_t*, size_t);
	size_t Write(const uint8_t*, size_t);
	std::string GetByteIndex();
	void Close();

	std::string mPhysicalPath;

private:
};