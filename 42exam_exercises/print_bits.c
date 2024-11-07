
#include <unistd.h>

void    print_bits(unsigned char octet)
{
	unsigned char	bits;
	int	i;

	i = 8;
	bits = 0;
	while (i--)
	{
		bits = (octet >> i & 1) + '0';
		write (1, &bits, 1);
	}
}

