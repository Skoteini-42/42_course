#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:

	std::string type;

	public:

	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual void	makeSound() const = 0;
	std::string	getType() const;
	virtual void	setIdea(int index, const std::string& idea);
    virtual std::string	getIdea(int index) const;
};

#endif
