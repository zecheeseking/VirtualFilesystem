#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "File.h"

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

	  void MountDirectory(const std::string & directory);
    std::string GetPhysicalFilePath(const std::string & filename) const;
    void GetFilesInDirectory(std::vector<File>& fileTable, const std::string & directory)const;
    void GetFilesWithExtension(std::vector<File>& fileTable, const std::string & extension) const;

    void LogAllFiles() const;

private:
    std::vector<File> m_Files;

    FileSystem(const FileSystem & fileSystem) {};
    FileSystem& operator=(const FileSystem & fileSystem){};
};
