#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Abstract animals test ===\n" << std::endl;
    //Animal* meta = new Animal(); <- abstract test
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    std::cout << "\n=== Polymorphism test === \n" << std::endl;
    std::cout << dog->getType() << ": ";
    dog->makeSound();
    std::cout << cat->getType() << ": ";
    cat->makeSound();

    std::cout << "\n=== Brain access test === \n" << std::endl;
    dog->setIdea(0, "I'm a good boy");
    cat->setIdea(0, "I'm a naughty cat");
    std::cout << "Dog idea: " << dog->getIdea(0) << std::endl;
    std::cout << "Cat idea: " << cat->getIdea(0) << std::endl;

    std::cout << "\n=== Deep copy test === \n" << std::endl;
    Dog original;
    original.setIdea(0, "I'm the original dog");
    Dog copy = original;
    copy.setIdea(0, "I'm a copy dog");

    std::cout << "Original: " << original.getIdea(0) << std::endl;
    std::cout << "Copy: " << copy.getIdea(0) << std::endl;
    
    std::cout << "\n === Cleanup === \n" << std::endl;
    delete dog;
    delete cat;
    
    return (0);
}
