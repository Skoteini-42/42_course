#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Array of animals test ===\n" << std::endl;
    
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog(); 
    animals[2] = new Cat();
    animals[3] = new Cat();
    
    // Test polymorphism
    for (int i = 0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
 
    // Test deep copy
    std::cout << "\n=== Deep copy test === \n" << std::endl;
    Dog original;
    original.setIdea(0, "I'm the original dog");
    Dog copy = original;
    copy.setIdea(0, "I'm a copy dog");
    
    std::cout << "Original: " << original.getIdea(0) << std::endl;
    std::cout << "Copy: " << copy.getIdea(0) << std::endl;
    
    // Cleanup
    std::cout << "\n === Cleanup === \n" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    return (0);
}
