#include "FileSystem.h"

#include <iostream>
#include <dirent.h>

FileSystem::FileSystem() {}

FileSystem::~FileSystem() {}

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
                MountDirectory(directory + entity->d_name + '/');
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
    for (const File & f : m_Files)
        if(f.mPhysicalPath.find(filename) != std::string::npos)
            return f.mPhysicalPath;

   return "";
}

void FileSystem::GetFilesInDirectory(std::vector<std::string>& fileTable, const std::string & directory)const {
    for (const File & f : m_Files)
    {
        if (f.mPhysicalPath.find(directory) != std::string::npos)
            fileTable.push_back(f.mPhysicalPath);
    }
}

void FileSystem::GetFilesWithExtension(std::vector<std::string>& fileTable, const std::string & extension)const {
    for(const File & f : m_Files)
    {
        if(f.mPhysicalPath.find(extension) != std::string::npos)
             fileTable.push_back(f.mPhysicalPath);
    }
}

std::unique_ptr<File> FileSystem::GetFile(const std::string & filename) const {
    std::cout << "Linux GetFile() implementation needed!";
    return nullptr;
}

std::unique_ptr<File> FileSystem::GetOutputFile(const std::string & filename) const {
    std::cout << "Linux GetOutputFile() implementation needed!";
    return nullptr;
}

void FileSystem::LogAllFiles() const
{
    for(auto f : m_Files)
        std::cout << f.mPhysicalPath << std::endl;
};
