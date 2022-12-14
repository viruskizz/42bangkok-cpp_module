#include "data.hpp"
#include <iostream>

int main( void )
{
	Data *data = new Data;

	data->key = "Araiva";
	data->value = 30;

	std::cout << "Key: " << deserialize(serialize(data))->key << std::endl;
	std::cout << "Value: " << deserialize(serialize(data))->value << std::endl;

	delete data;

	return 0;
}
