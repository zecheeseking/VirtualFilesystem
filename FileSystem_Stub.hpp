#include "FileSystem.h"

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

void FileSystem::MountDirectory(const std::string & directory) {}

void FileSystem::MountDirectory(const std::string & directory) {}

std::string FileSystem::GetPhysicalFilePath(const std::string & filename) const {return nullptr;}

void FileSystem::GetFilesInDirectory(std::vector<std::string>& fileTable, const std::string & directory) const {}

void FileSystem::GetFilesWithExtension(std::vector<std::string>& fileTable, const std::string & extension) const {}

std::unique_ptr<File> FileSystem::GetFile(const std::string & filename) const {}

std::unique_ptr<File> FileSystem::GetOutputFile(const std::string & filename) const {}

void FileSystem::LogAllFiles() const {}
