#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <map>

#include "FileSystem.h"
#include "File.h"


// FileSystem fs;
//
// printf("Enter mount path: \n");
//
// std::string dir = "";
//
// #if defined(PLATFORM_WIN) && defined(_DEBUG)
//     dir = "D:\\Users\\Christopher\\Pictures\\Work\\";
// #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
//     dir = "/home/chris/Documents/Test/";
// #else
//     std::cin >> dir;
// #endif
//
// fs.MountDirectory(dir);
// printf("finished mount.\n");
// fs.LogAllFiles();
//
// std::vector<std::string> fileTable;
// std::string dirSearch = "";
// #if defined(PLATFORM_WIN) && defined(_DEBUG)
//     dirSearch = "Test\\";
// #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
//     dirSearch = "More/";
// #else
//     std::cin >> dirSearch;
// #endif
//
// fs.GetFilesInDirectory(fileTable, dirSearch);
//
// printf("**********\n");
// printf("Files in directory\n");
// printf("**********\n");
//
// for (auto s : fileTable)
//     std::cout << s << std::endl;
//
// fileTable.clear();
// std::string extension = "";
// #if defined(PLATFORM_WIN) && defined(_DEBUG)
//     extension = ".mp4";
// #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
//     extension = ".txt";
// #else
//     std::cin >> extension;
// #endif
//
// fs.GetFilesWithExtension(fileTable, extension);
//
// printf("**********\n");
// printf("Files with extension\n");
// printf("**********\n");
//
// for (auto s : fileTable)
//     std::cout << s << std::endl;
//
// std::string fileName = "";
// #if defined(PLATFORM_WIN) && defined(_DEBUG)
//     fileName = "test.txt";
// #elif defined(PLATFORM_LINUX) && defined(_DEBUG)
//     fileName = "test.txt";
// #else
//     std::cin >> fileName;
// #endif
//
// std::string result = fs.GetPhysicalFilePath(fileName);
// printf("**********\n");
// printf("File physical path search\n");
// printf("**********\n");
// printf(result.c_str());
//
// std::unique_ptr<File> input_file = fs.GetFile("input.txt");
// std::unique_ptr<File> output_file = fs.GetOutputFile("output.txt");
//
// input_file->Open(FileMode::Read);
// output_file->Open(FileMode::Write);
//
// size_t read_byte_count, written_byte_count;
// std::vector<uint8_t> buffer;
//
// constexpr int buffer_size = 1024;
// buffer.resize(buffer_size);
//
// do {
//     read_byte_count = input_file->Read(buffer.data(), buffer.size());
//
//     if(read_byte_count != 0)
//         written_byte_count = output_file->Write(buffer.data(), read_byte_count);
// } while (read_byte_count != 0);
//
// input_file->Close();
// output_file->Close();

class FileSystemIO
{
public:
    FileSystemIO() : mEnd(false)
    {
		m_pFileSystem = new FileSystem();

        FileSystem & fs = *m_pFileSystem;
		std::vector<std::string> & fileTable = mFileTable;
		bool & end = mEnd;

		auto mountDir = [&fs](const std::string & path){
			#if defined(PLATFORM_WIN) && defined(_DEBUG)
				fs.MountDirectory("D:\\Users\\Christopher\\Pictures\\Work\\");
			#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
				fs.MountDirectory("/home/chris/Documents/Test/");
			 #else
				fs.MountDirectory(path);
			 #endif

			fs.LogAllFiles();
		};

		auto searchDir = [&fs, &fileTable](const std::string & path) {
			fileTable.clear();

			#if defined(PLATFORM_WIN) && defined(_DEBUG)
				fs.GetFilesInDirectory(fileTable, "Test\\");
			#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
				fs.GetFilesInDirectory(fileTable, "More/");
			#else
				fs.GetFilesInDirectory(fileTable, dirSearch);
			#endif
			
			for (auto s : fileTable)
				std::cout << s << std::endl;
		};

		auto searchExt = [&fs, &fileTable](const std::string & path) {
			fileTable.clear();

			#if defined(PLATFORM_WIN) && defined(_DEBUG)
				fs.GetFilesWithExtension(fileTable, ".mp4");
			#elif defined(PLATFORM_LINUX) && defined(_DEBUG)
				fs.GetFilesWithExtension(fileTable, ".txt");
			#else
				fs.GetFilesWithExtension(fileTable, extension);
			#endif
			
			for (auto s : fileTable)
				std::cout << s << std::endl;
		};

		auto searchPath = [&fs](const std::string & file) {
			std::string result = fs.GetPhysicalFilePath(file);
			printf(result.c_str() + '\n');
		};

        auto exit = [&end](const std::string & path){
			end = true;
		};

		m_Commands["mount"] = mountDir;
		m_Commands["searchdir"] = searchDir;
		m_Commands["searchext"] = searchExt;
		m_Commands["searchpath"] = searchPath;

        m_Commands["exit"] = exit;
    }

    void Execute(const std::string & command) const{

		size_t splitIndex = command.find(' ');
		auto commandFiltered = command.substr(0, splitIndex);
		auto input = command.substr(splitIndex + 1, command.size() - 1 - splitIndex);

        auto cmd = m_Commands.find(commandFiltered);
		if (cmd != m_Commands.end())
			cmd->second(input);
		else
			printf("FileSystemIO::Execute> Unrecognized command.");
    }

	void PrintFileTableVector(){

	}

	bool End() { return mEnd; }

private:

	bool mEnd;
    FileSystem * m_pFileSystem;
	std::vector<std::string> mFileTable;
    std::map<std::string, std::function<void(const std::string &)>> m_Commands;
};

int main()
{
    FileSystemIO fsio;

	while(!fsio.End())
    {
        std::string cmd;
        std::cout << ">";
		std::getline(std::cin,cmd);
        fsio.Execute(cmd);
	};
}
