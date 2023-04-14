#include "BitcoinExchange.hpp"

bool		isValidDate(std::string const s);
bool		isValidValue(std::string const s, bool isInt);
int			dateToTimestamp(std::string date);
std::string	closestDate(std::string date, std::map<std::string, float> data);

/************************************************
 * Setup default construct and  member function *
 ************************************************/

BitcoinExchange::BitcoinExchange(): _filedata("data.csv") {
	this->_execfile(this->_filedata, &BitcoinExchange::_addData);
};

BitcoinExchange::BitcoinExchange(std::string name): _filedata(name){
	this->_execfile(this->_filedata, &BitcoinExchange::_addData);
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	this->_filedata = rhs._filedata;
	this->_fileinput = rhs._fileinput;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "~Deconstructor~" << std::endl;
}

std::string	const BitcoinExchange::getFiledata() const {
	return this->_filedata;
}

std::map<std::string, float> const BitcoinExchange::getData() const {
	return this->_data;
}

float BitcoinExchange::getValue(std::string key) const {
	return this->_data.at(key);
}

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs ) {
	o << rhs.getData();
	return o;
}

std::ostream & operator<<( std::ostream & o, std::map<std::string, float> const & rhs ) {
	for (std::map<std::string, float>::const_iterator it = rhs.begin(); it != rhs.end(); ++it)
		o << it->first << " => " << it->second << '\n';
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/

void BitcoinExchange::exchange(std::string file) {
	this->_fileinput = file;
	this->_execfile(file, &BitcoinExchange::_cal);
}

void	BitcoinExchange::_addData(std::string & s) {
	std::string key = s.substr(0, s.find(","));
	std::string value = s.substr(s.find(",") + 1);
	if (!isValidDate(key))
		return ;
	else if (!isValidValue(value, false))
		return ;
	else 
		this->_data[key] = std::atof(value.c_str());
}

void	BitcoinExchange::_cal(std::string & line) {
	if (line.length() < 12 || line.find("|") == std::string::npos)
		return (std::cerr << "Error: bad input => " << line << std::endl, (void) NULL);
	std::string date = line.substr(0, 10);
	std::string value = line.substr(line.find("|") + 2);
	if (!isValidDate(date)) {
		return ;
	} else if (!isValidValue(value, true)) {
		return ;
	}
	int val = atoi(value.c_str());
	if (val < 0)
		return (std::cerr << "Error: not a positive number => " << val << std::endl, (void) NULL);
	if (val > 1000)
		return (std::cerr << "Error: too large number => " << val << std::endl, (void) NULL);
	float data;
	if (this->_data.find(date) != this->_data.end())
		data = this->_data.at(date);
	else
		data =  this->_data.at(closestDate(date, this->_data));
	std::cout << date << " => " << val << "*" << data << " = " << val * data << std::endl;
}

void	BitcoinExchange::_execfile(std::string & filename, void (BitcoinExchange::*func)(std::string & line)) {
	std::fstream	file;
	std::string		line;
	file.open(filename.c_str());
	if (!file)
		throw BitcoinExchange::ReadFileException();
	else
	{
		int i = 0;
		while (true) {
			if (++i && !std::getline(file, line))
				break;
			if (i != 1)
				(this->*func)(line);
			else if (i == 1 && filename == this->_fileinput)
				std::cout << line << std::endl;
		}
		std::cin.clear();
		file.close();
	}
}

/************************************************
 *               Utility function               *
 ************************************************/

bool	isValidDate(std::string const s) {
	if (s.length() != 10 || s.at(4) != '-' || s.at(7) != '-')
		return (std::cerr << "Error: bad input => " << s << std::endl, false);
	int	y = atoi(s.substr(0, 4).c_str());
	int	m = atoi(s.substr(5, 2).c_str());
	int	d = atoi(s.substr(8, 2).c_str());
	if (y < 1990 || m < 0 || m > 12 || d < 0 || d > 31)
		return (std::cerr << "Error: bad input => " << s << std::endl, false);
	return true;
}

bool	isValidValue(std::string const s, bool isInt) {
	if (s.length() == 0 || s.empty())
		return (std::cerr << "Error: invalid value => " << s << std::endl, false);
	for (int i = 0; i < (int) s.length(); i++) {
		if (!isdigit(s.at(i)) && (isInt && s.at(i) == '.'))
			return (std::cerr << "Error: invalid value => " << s << std::endl, false);
	}
	return true;
}

int	dateToTimestamp(std::string date) {
	int dt = 60 * 24;
	int	y = atoi(date.substr(0, 4).c_str());
	int	m = atoi(date.substr(5, 2).c_str());
	int	d = atoi(date.substr(8, 2).c_str());
	return (y * 365 * dt) + (m * 30 * dt) + (d * dt);
}

std::string closestDate(std::string date, std::map<std::string, float> data) {
	int timestamp = dateToTimestamp(date);
	for (std::map<std::string, float>::reverse_iterator it = data.rbegin(); it != data.rend(); ++it) {
		if (dateToTimestamp(it->first) < timestamp) {
			return it->first;
		}
	}
	return data.begin()->first;
}
