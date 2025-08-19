#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integerValue)
{
	std::cout << "Int constructor called" << std::endl;
	_value = integerValue  << _fractionalBits;
}

Fixed::Fixed(const float floatingValue)
{
	std::cout << "Float constructor called" << std::endl;
	_value  = roundf(floatingValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& objectToCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = objectToCopy;
}

Fixed& Fixed::operator=(const Fixed& objectToAssignFrom)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &objectToAssignFrom)
		this->_value = objectToAssignFrom.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return (float)_value / (1 << _fractionalBits);
}

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &valueToPrint)
{
	outputStream << valueToPrint.toFloat();
	return (outputStream);
}
