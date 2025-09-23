#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	// Init
	Fixed a(21);
	Fixed b(10.5f);
	Fixed c(2.5f);

	// Basic output
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	// Comparison operators
	std::cout << "\nComparisons:" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	// Arithmetic operations
	std::cout << "\nArithmetic:" << std::endl;
	std::cout << "b + c: " << (b + c) << std::endl;
	std::cout << "b - c: " << (b - c) << std::endl;
	std::cout << "b * c: " << (b * c) << std::endl;
	std::cout << "b / c: " << (b / c) << std::endl;

	// Increment/Decrement
	std::cout << "\nIncrement/Decrement:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;

	// Min/Max functions
	std::cout << "\nMin/Max:" << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    b = a;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	// Original subject test
	std::cout << "\n=== Subject Test ===" << std::endl;
	Fixed d;
	Fixed const e(Fixed(5.05f) * Fixed(2));
	
	std::cout << d << std::endl;
	std::cout << ++d << std::endl;
	std::cout << d << std::endl;
	std::cout << d++ << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << Fixed::max(d, e) << std::endl;

	return 0;
}
