
#include "FileSystem.h"
#include <string>
#include <iostream>

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

    std::cin.get();
}
