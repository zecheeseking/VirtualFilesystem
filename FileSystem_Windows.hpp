#include "FileSystem.h"

#include <iostream>
#include <windows.h>
#include <memory>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

void FileSystem::Test() {}

void FileSystem::MountDirectory(const std::string & directory) {
    WIN32_FIND_DATAA find_data;

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
    				m_Files.push_back(directory + find_data.cFileName);
    		}
    	}while (FindNextFileA(handle, &find_data) != 0);

    	FindClose(handle);
}

std::string FileSystem::GetPhysicalFilePath(const std::string & filename) const {
   std::cout << "Windows GetPhysicalFilePath implementation needed!\n";
   return nullptr;
}

void FileSystem::GetFilesInDirectory(std::vector<File>& fileTable, const std::string & directory)const {
    for (const File & f : m_Files)
	{
		if (f.mPhysicalPath.find(directory) != std::string::npos)
			fileTable.push_back(f.mPhysicalPath);
	}
}

void FileSystem::GetFilesWithExtension(std::vector<File>& fileTable, const std::string & extension)const {
   std::cout << "Windows GetFilesWithExtension implementation needed!\n";
}
