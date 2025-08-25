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

//Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

//Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//Increment/Decrement
Fixed &Fixed::operator++()
{
	_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value += 1;
	return (temp);
}

Fixed &Fixed::operator--()
{
	_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value -= 1;
	return (temp);
}

//min/max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &valueToPrint)
{
	outputStream << valueToPrint.toFloat();
	return (outputStream);
}
