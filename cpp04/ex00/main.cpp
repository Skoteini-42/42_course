#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== POLYMORPHISM TEST ===\n" << std::endl;

	std::cout << "\n1. Valid test (heap):\n" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
    
    delete meta;
    delete i;
    delete j;

	std::cout << "\n2. Valid test (stack):\n" << std::endl;
	{
        Animal a;
        Cat c;
        Dog d;
        std::cout << a.getType() << ": ";
        a.makeSound();
        std::cout << c.getType() << ": ";
        c.makeSound();
        std::cout << d.getType() << ": ";
        d.makeSound();
	}

	std::cout << "\n3. Wrong test (heap):\n" << std::endl;
    const WrongAnimal*   meta2 = new WrongAnimal();
    const WrongAnimal*   k = new WrongCat();
    const WrongCat*      l = new WrongCat();

    std::cout << meta2->getType() << ": ";
    meta2->makeSound();
    std::cout << k->getType() << " (as WrongAnimal): ";
    k->makeSound();
    std::cout << l->getType() << " (as WrongCat): ";
    l->makeSound();

    delete meta2;
    delete k;
    delete l;

	std::cout << "\n=== END OF TEST ===\n" << std::endl;

	return 0;
}
