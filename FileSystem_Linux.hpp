#include "FileSystem.h"

#include <iostream>
#include <dirent.h>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

void FileSystem::Test() {}

void FileSystem::MountDirectory(const std::string & directory) {

    std::cout << "Searching\n";
    auto dir = opendir(directory.c_str());

    if(dir == NULL){
        std::cout << "Cannot process directory" << std::endl;
		    return;
	  }

    auto entity = readdir(dir);

    while(entity != NULL)
    {
        //Check if directory
        if(entity->d_type == DT_DIR)
        {
            if(entity->d_name[0] != '.')
            {
                //If here it's a valid path, recursively check the subdir
            }
        }
        //Else check if file.
        else if(entity->d_type == DT_REG)
        {
            m_Files.push_back(directory + entity->d_name);
        }

        entity = readdir(dir);
    }

    closedir(dir);
}

std::string FileSystem::GetPhysicalFilePath(const std::string & filename) const {
   std::cout << "Linux GetPhysicalFilePath implementation needed!\n";
   return "";
}

void FileSystem::GetFilesInDirectory(std::vector<File>& fileTable, const std::string & directory)const {
   std::cout << "Linux GetFilesInDirectory implementation needed!\n";
}

void FileSystem::GetFilesWithExtension(std::vector<File>& fileTable, const std::string & extension)const {
   std::cout << "Linux GetFilesWithExtension implementation needed!\n";
}

void FileSystem::LogAllFiles() const
{
    for(auto f : m_Files)
        std::cout << f.mPhysicalPath << std::endl;
};
