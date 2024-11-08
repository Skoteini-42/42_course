
int	max(int* tab, unsigned int len)
{
	int	nb;
	int	i;

	nb = 0;
	if (!tab)
		return (0);
	i = 0;
	while (i < len)
	{
		if (tab[i] > nb)
			nb = tab[i];
		i++;
	}
	return (nb);
}
