#include "FileSystem.h"

#include <iostream>
#include <windows.h>
#include <memory>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

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
	for (const std::string & s : m_Files)
		if (s.find(filename) != std::string::npos)
			return s;

	return "";
}

void FileSystem::GetFilesInDirectory(std::vector<std::string>& fileTable, const std::string & directory)const {
    for (const std::string & s : m_Files)
	{
		if (s.find(directory) != std::string::npos)
			fileTable.push_back(s);
	}
}

void FileSystem::GetFilesWithExtension(std::vector<std::string>& fileTable, const std::string & extension)const {
   for(const std::string & s : m_Files)
   {
       if(s.find(extension) != std::string::npos)
            fileTable.push_back(s);
   }
}

std::unique_ptr<File> FileSystem::GetFile(const std::string & filename) const {
    for(const std::string & s : m_Files)
        if(s.find(filename) != std::string::npos)
            {
                auto ptr = std::unique_ptr<File>(new File(s));
                return ptr;
            }

    std::cout << "Could not find file!\n";
	return nullptr;
}

std::unique_ptr<File> FileSystem::GetOutputFile(const std::string & filename) const {
    for(const std::string & s : m_Files)
        if(s.find(filename) != std::string::npos)
            {
                auto ptr = std::unique_ptr<File>(new File(s));
                return ptr;
            }

    std::cout << "Could not find output file!\n";
    return nullptr;
}

void FileSystem::LogAllFiles() const
{
    for(auto s : m_Files)
        std::cout << s << std::endl;
};
