#pragma once

#include "FileMode.h"
#include <string>
#include <stdint.h>
#include <vector>

#if defined(PLATFORM_WINDOWS)
	#include "file_windows_includes.h"
#endif

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


private:
	std::string mPhysicalPath;

	#if defined(PLATFORM_WINDOWS)
		#include "file_windows_members.h"
	#elif defined(PLATFORM_LINUX)
		#include "file_linux_members.h"
};
