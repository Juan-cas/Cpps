#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <memory>

class Zombie
{
public:
    Zombie(std::string name);
    ~Zombie(void);

    void randomChump(std::string name);
    void announce();
    std::string get_name() const;
private:
    std::string name;
};

Zombie* newZombie(std::string name);

#endif
