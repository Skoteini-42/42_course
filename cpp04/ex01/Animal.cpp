#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "**Makes some animal sounds**" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::setIdea(int index, const std::string& idea)
{
	(void)index;
	(void)idea;
}

std::string Animal::getIdea(int index) const
{
	(void)index;
	return ("No ideas");
}
