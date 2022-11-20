#include "MyFile.hpp"

MyFile::MyFile( std::string name ): _name(name) {
	this->_data = this->read(name);
}

MyFile::~MyFile () {}

void	MyFile::write ( std::string data, std::string filename ) {
	std::ofstream ofs(filename.c_str(), std::ios::trunc | std::ios::out);
	ofs << data;
	ofs.close();
}

std::string	MyFile::read ( std::string name ) {
	std::ifstream	ifs(name.c_str());
	std::string		data;
	char			buf;

	if (!ifs.is_open()) {
		std::cerr << RED << "file cannot open!" << RESET << std::endl;
		data = "";
	} else {
		while (ifs.get(buf)) {
			data.push_back(buf);
		}
	}
	ifs.close();
	return data;
}

std::string	MyFile::str_repleace (std::string str, std::string s1, std::string s2) {
	std::string	result;
	std::size_t	found;
	std::size_t	search = 0;
	
	if (s1.empty() ||s2.empty())
		return str;

	while (true) {
		found = str.find(s1, search);
		if (found == std::string::npos)
			break;
		result += str.substr(search, found - search);
		result += s2;
		search = found + s1.length();
	}
	if (search < str.length())
		result += str.substr(search);
	return result;
}

void	MyFile::cat() {
	std::cout << this->_data;
}

std::string	MyFile::sed( std::string s1, std::string s2) {
	return str_repleace(this->_data, s1, s2);
}

void	MyFile::cat( std::string filename) {
	std::cout << read(filename);
}

std::string	MyFile::getName() { return this->_name; }
std::string	MyFile::getData() { return this->_data; }