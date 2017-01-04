
#include "FileSystem.h"
#include <string>
#include <iostream>
#include "File.h"

int main()
{
    FileSystem fs;

    std::cout << "Enter mount path: \n";

    std::string dir = "";

    #if defined(PLATFORM_WIN) && defined(_DEBUG)
        dir = "D:\\Users\\Christopher\\Pictures\\Work\\";
    #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
        dir = "/home/chris/Documents/Test/";
    #else
        std::cin >> dir;
	#endif

    fs.MountDirectory(dir);
	fs.LogAllFiles();

    std::vector<File> fileTable;
	std::string dirSearch = "";
	#if defined(PLATFORM_WIN) && defined(_DEBUG)
		dirSearch = "Test\\";
	#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
		dirSearch = "/home/chris/Documents/Test/";
	#else
		std::cin >> dir;
	#endif

    fs.GetFilesInDirectory(fileTable, dirSearch);

	std::cout << "**********" << std::endl;
	std::cout << "Files in directory" << std::endl;
	std::cout << "**********" << std::endl;

	for (auto f : fileTable)
		std::cout << f.mPhysicalPath << std::endl;

    std::cin.get();
}
