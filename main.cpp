
#include "FileSystem.h"
#include <string>
#include <iostream>

int main()
{
    FileSystem fs;

    std::cout << "Enter mount path: \n";

	fs.Test();
	std::string dir = "directory";
    fs.MountDirectory(dir);

    std::cin.get();
}
