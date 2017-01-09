#include "File.h"
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

File::File(const std::string & physicalPath) :
	mPhysicalPath(physicalPath),
	mFileDescriptor(-1)
{
}

File::~File(){}

bool File::Open(FileMode mode)
{
	int flags;

	if(mode == FileMode::ReadWrite)
		mFileDescriptor = open(mPhysicalPath.c_str(), O_RDWR);
	else if(mode == FileMode::Write)
		mFileDescriptor = open(mPhysicalPath.c_str(), O_WRONLY);
	else if(mode == FileMode::Read)
		flags = flags || O_RDONLY;


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
	return read(mFileDescriptor, buffer, length);
}

size_t File::Write(const uint8_t * buffer, size_t length)
{
	//Copies from a different buffer
	return write(mFileDescriptor, buffer, length);
}

std::string File::GetByteIndex()
{
	return std::string();
}

void File::Close()
{
	close(mFileDescriptor);
}
