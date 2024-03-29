#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <limits>

class Zombie {
public:
    Zombie(std::string name);
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);

private:
    std::string name_;
};
#endif