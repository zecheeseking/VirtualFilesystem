#pragma once

#include <string>
#include <iostream>
#include <vector>

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

    void Test();

	void MountDirectory(const std::string & directory);

    void LogAllFiles() const
    {
        for(auto s : m_Files)
            std::cout << s << std::endl;
    };

private:
    std::vector<std::string> m_Files;

    FileSystem(const FileSystem & fileSystem) = delete;
    FileSystem& operator=(const FileSystem & fileSystem) = delete;
};
