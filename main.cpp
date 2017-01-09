

#include <string>
#include <iostream>
#include <memory>

#include "FileSystem.h"
#include "File.h"

int main()
{
    FileSystem fs;

    printf("Enter mount path: \n";)

    std::string dir = "";

    #if defined(PLATFORM_WIN) && defined(_DEBUG)
        dir = "D:\\Users\\Christopher\\Pictures\\Work\\";
    #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
        dir = "/home/chris/Documents/Test/";
    #else
        std::cin >> dir;
	#endif

  fs.MountDirectory(dir);
  printf("finished mount.\n");
  fs.LogAllFiles();

    std::vector<std::string> fileTable;
	std::string dirSearch = "";
	#if defined(PLATFORM_WIN) && defined(_DEBUG)
		dirSearch = "Test\\";
	#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
		dirSearch = "Happytimes/";
	#else
		std::cin >> dirSearch;
	#endif

    fs.GetFilesInDirectory(fileTable, dirSearch);

	printf("**********");
	printf("Files in directory");
	printf("**********");

	for (auto s : fileTable)
		std::cout << s << std::endl;

    fileTable.clear();
    std::string extension = "";
    #if defined(PLATFORM_WIN) && defined(_DEBUG)
    	extension = ".mp4";
    #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
    	extension = ".txt";
    #else
    	std::cin >> extension;
    #endif

    fs.GetFilesWithExtension(fileTable, extension);

    printf("**********");
    printf("Files with extension");
    printf("**********");

    for (auto s : fileTable)
    	std::cout << s << std::endl;

	std::string fileName = "";
	#if defined(PLATFORM_WIN) && defined(_DEBUG)
		fileName = "test.txt";
	#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
		fileName = "TEST1.txt";
	#else
		std::cin >> fileName;
	#endif

	std::string result = fs.GetPhysicalFilePath(fileName);
	printf("**********");
	sprintf("File physical path search");
	printf("**********");
	printf(result);

    std::unique_ptr<File> input_file = fs.GetFile("input.txt");
    std::unique_ptr<File> output_file = fs.GetOutputFile("output.txt");

    input_file->Open(FileMode::Read);
    output_file->Open(FileMode::Write);

	size_t read_byte_count, written_byte_count;
	std::vector<uint8_t> buffer;

	constexpr int buffer_size = 1024;
	buffer.resize(buffer_size);

	do {
		read_byte_count = input_file->Read(buffer.data(), buffer.size());
		if(read_byte_count != 0)
			written_byte_count = output_file->Write(buffer.data(), buffer.size());

	} while (read_byte_count > 0);

	input_file->Close();
	output_file->Close();

    std::cin.get();
}
