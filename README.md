# C++ Module

## Canonical Form

### Base canonical form template

There is template base class with constructor overload

- Default constructor (void)
- Argument constructor (std::string name)
- Copy constructor
- Assignment constructor

#### Base.hpp

```c++
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base {

protected:

    std::string	_name;

public:

    Base(void);
    Base(std::string name);
    Base(Base const & src);
    ~Base(void);

    Base & operator=(Base const & rhs);

};

#endif
```

#### Base.cpp

```c++
#include "Base.hpp"

Base::Base(): _name("") {
    std::cout << "Default constructor overload" << std::endl;
    std::cout << "" << std::endl;
};

Base::Base(std::string name): _name(name){
    std::cout << "Argument constructor overload" << std::endl;
};

Base::Base(Base const & src) {
    std::cout << "Copy constructor overload" << std::endl;
    *this = src;
}

Base & Base::operator=(Base const & rhs) {
    std::cout << "Assignment constructor overload" << std::endl;
    if (this == &rhs)
        return *this;
    this->_name = rhs._name;
    return *this;
}

Base::~Base() {
    std::cout << "~Deconstructor~" << std::endl;
}
```
