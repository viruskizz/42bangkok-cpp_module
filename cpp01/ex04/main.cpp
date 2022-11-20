#include <iostream>
#include "MyFile.hpp"

int main(int argc, char *argv[])
{
	std::string	filename;

	if (argc < 4) {
		std::cerr << "Need 3 argument: filename, s1, s1" << std::endl;
		return (0);
	}
	filename = argv[1];
	MyFile myFile = MyFile(argv[1]);
	MyFile::write(myFile.sed(argv[2], argv[3]), filename + ".replace");
	return (0);
}
