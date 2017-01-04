#include "FileSystem.h"

#include <iostream>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

void FileSystem::Test() {}

void FileSystem::MountDirectory(const std::string & directory) { std::cout << "Mounting"; }

void FileSystem::MountDirectory(const std::string & directory) {
    std::cout << "Linux MountDirectory implementation needed!\n";
}

std::string FileSystem::GetPhysicalFilePath(const std::string & filename) const {
   std::cout << "Linux MountDirectory implementation needed!\n";
   return nullptr;
}

void FileSystem::GetFilesInDirectory(std::vector<File>& fileTable, const std::string & directory)const {
   std::cout << "Linux MountDirectory implementation needed!\n";
}

void FileSystem::GetFilesWithExtension(std::vector<File>& fileTable, const std::string & extension)const {
   std::cout << "Linux MountDirectory implementation needed!\n";
}
