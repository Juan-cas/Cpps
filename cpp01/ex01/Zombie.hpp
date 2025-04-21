#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <memory>

typedef std::string str;

class Zombie
{
public:
    Zombie();
    ~Zombie(void);

    void announce() const;
    void set_name(const str& name);
    str get_name() const;
private:
    str name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
