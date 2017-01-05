
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
  std::cout <<"finished mount.\n";
  fs.LogAllFiles();

    std::vector<File> fileTable;
	std::string dirSearch = "";
	#if defined(PLATFORM_WIN) && defined(_DEBUG)
		dirSearch = "Test\\";
	#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
		dirSearch = "/home/chris/Documents/Test/";
	#else
		std::cin >> dirSearch;
	#endif

    fs.GetFilesInDirectory(fileTable, dirSearch);

	std::cout << "**********" << std::endl;
	std::cout << "Files in directory" << std::endl;
	std::cout << "**********" << std::endl;

	for (auto f : fileTable)
		std::cout << f.mPhysicalPath << std::endl;

    fileTable.clear();
    std::string extension = "";
    #if defined(PLATFORM_WIN) && defined(_DEBUG)
    	extension = ".mp4";
    #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
    	extension = "/home/chris/Documents/Test/";
    #else
    	std::cin >> extension;
    #endif

    fs.GetFilesWithExtension(fileTable, extension);

    std::cout << "**********" << std::endl;
    std::cout << "Files with extension" << std::endl;
    std::cout << "**********" << std::endl;

    for (auto f : fileTable)
    	std::cout << f.mPhysicalPath << std::endl;

	std::string fileName = "";
	#if defined(PLATFORM_WIN) && defined(_DEBUG)
		fileName = "test.txt";
	#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
		fileName = "/home/chris/Documents/Test/";
	#else
		std::cin >> fileName;
	#endif

	std::string result = fs.GetPhysicalFilePath(fileName);
	std::cout << "**********" << std::endl;
	std::cout << "File physical path search" << std::endl;
	std::cout << "**********" << std::endl;
	std::cout << result << std::endl;


    std::cin.get();
}
