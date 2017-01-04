#include "FileSystem.h"

#include <iostream>
#include <windows.h>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

void FileSystem::Test() {}

void FileSystem::MountDirectory(const std::string & directory) {
    WIN32_FIND_DATAA find_data;

    	//CHECK DIRECTORY EXISTS.
    	auto filePath = directory.substr(0,directory.size() - 1);
    	HANDLE handle = FindFirstFileA(filePath.c_str(), &find_data);

    	if (handle == INVALID_HANDLE_VALUE)
    	{
    		std::cerr << "Unable to open directory " << directory <<
    			" error code: (" << std::hex << GetLastError() << ")\n";

    		return;
    	}

    	filePath = directory + "*.*";
    	handle = FindFirstFileA(filePath.c_str(), &find_data);
    	do {
    		if ((find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
    		{
    			if (strcmp(find_data.cFileName, ".") == 0
    				|| strcmp(find_data.cFileName, "..") == 0)
    			{
    				continue;
    			}
    			else
    			{
    				MountDirectory(directory + find_data.cFileName + "\\");
    			}
    		}
    		else
    		{
    			if (strcmp(find_data.cFileName, ".") == 0
    				|| strcmp(find_data.cFileName, "..") == 0)
    			{
    				continue;
    			}
    			else
    				m_Files.push_back(find_data.cFileName);
    		}
    	}while (FindNextFileA(handle, &find_data) != 0);

    	FindClose(handle);
}

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
