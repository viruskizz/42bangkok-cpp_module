#ifndef DATA_HH
#define DATA_H

#include <string>
#include <stdint.h>

struct Data {
	std::string	key;
	int			value;
};

uintptr_t	serialize(Data *data);
Data*		deserialize(uintptr_t data);

#endif
