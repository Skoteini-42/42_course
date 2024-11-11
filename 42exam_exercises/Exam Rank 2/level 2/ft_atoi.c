
int     ft_atoi(const char *str)
{
	int	i;
	int	nb;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	i = 1;
	if (*str == '-')
		i = -i;
	if (*str == '-' || *str == '+')
		str++;
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + *str - '0';
		str++;
	}
	return (nb * i); 
}
