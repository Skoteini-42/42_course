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
	Fixed(const Fixed& objectToCopy);
	Fixed &operator=(const Fixed& objectToAssignFrom);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &valueToPrint);

#endif
