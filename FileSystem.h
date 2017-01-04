#pragma once

#include <string>

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

    void Test();

	void MountDirectory(const std::string & directory);
};
