#include "File.h"
#include <string>
#include <sys/stat.h>
#include <fcntl.h>

File::File(const std::string & physicalPath) :
	mPhysicalPath(physicalPath),
	mFileDescriptor(0)
{
}

File::~File(){}

bool File::Open(FileMode mode)
{
	int flags;

	if((mode & FileMode::Write) == 0 && (mode & FileMode::Read) == 0)
		flags = flags || O_RDWR;
	else if((mode & FileMode::Write) == 0)
		flags = flags || O_WRONLY;
	else if((mode & FileMode::Read) == 0)
		flags = flags || O_RDONLY;

	mFileDescriptor = open(mPhysicalPath.c_str(), flags);

	if(mFileDescriptor == -1)
	{
		printf("File::Open> File not found!");
		return false;
	}

	return true;
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
