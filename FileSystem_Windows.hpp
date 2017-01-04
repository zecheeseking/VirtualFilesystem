#include "FileSystem.h"

#include <iostream>
#include <windows.h>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

void FileSystem::Test() {}

void FileSystem::MountDirectory(const std::string & directory) { std::cout << "Mounting\n";}

// void FileSystem::MountDirectory(const std::string & directory) {
//     std::cout << "Windows MountDirectory implementation needed!\n";
// }

//std::string FileSystem::GetPhysicalFilePath(const std::string & filename) const {
//    std::cout << "Windows GetPhysicalFilePath implementation needed!\n";
//    return nullptr;
//}
//
//void FileSystem::GetFilesInDirectory(std::vector<std::string>& fileTable, const std::string & directory) {
//    std::cout << "Windows GetFilesInDirectory implementation needed!\n";
//}
//
//void FileSystem::GetFilesWithExtension(std::vector<std::string>& fileTable, const std::string & extension) {
//    std::cout << "Windows GetFilesWithExtension implementation needed!\n";
//}
