#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "File.h"

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

	  void MountDirectory(const std::string & directory);
    std::string GetPhysicalFilePath(const std::string & filename) const;
    void GetFilesInDirectory(std::vector<std::string>& fileTable, const std::string & directory)const;
    void GetFilesWithExtension(std::vector<std::string>& fileTable, const std::string & extension) const;

    std::unique_ptr<File> GetFile(const std::string & filename) const;
    std::unique_ptr<File> GetOutputFile(const std::string & filename) const;

    void LogAllFiles() const;

private:

    std::vector<std::string> m_Files;

    FileSystem(const FileSystem & fileSystem) {};
    FileSystem& operator=(const FileSystem & fileSystem){};
};
