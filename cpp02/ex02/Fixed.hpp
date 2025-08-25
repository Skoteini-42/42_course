#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

	int					_value;
	static const int	_fractionalBits = 8;

	public:

	Fixed();
	Fixed(const int integerValue);
	Fixed(const float floatingValue);
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static const	Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const	Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &valueToPrint);

#endif
