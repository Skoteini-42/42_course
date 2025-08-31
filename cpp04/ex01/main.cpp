#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Polymorphism test ===\n" << std::endl;
    
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog(); 
    animals[2] = new Cat();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deep copy test copy constuctor=== \n" << std::endl;
    Dog original;
    original.setIdea(0, "I'm the original dog");
    Dog copy = original;
    copy.setIdea(0, "I'm a copy dog");
    std::cout << "Original: " << original.getIdea(0) << std::endl;
    std::cout << "Copy: " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== Deep copy test assignment operator constuctor=== \n" << std::endl;
    Cat originalcat;
    Cat copycat;
    originalcat.setIdea(0, "I'm the original cat");
    copycat = originalcat;
    copycat.setIdea(0, "I'm a copy cat");
    std::cout << "Original cat: " << originalcat.getIdea(0) << std::endl;
    std::cout << "Copy cat: " << copycat.getIdea(0) << std::endl;

    std::cout << "\n === Cleanup === \n" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    return (0);
}
