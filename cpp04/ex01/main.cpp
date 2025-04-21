#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main( void )
{
    Animal *zoo[20];
    for (int i = 0; i < 10; i++)
    {
	zoo[i] = new Cat();
    }
    for (int i = 10; i < 20; i++)
    {
	zoo[i] = new Dog();
    }
    for (int i = 0; i < 10; i++)
    {
	delete zoo[i];
    }
    for (int i = 10; i < 20; i++)
    {
	delete zoo[i];
    }
    return 0;
}
