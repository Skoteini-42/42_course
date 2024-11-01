typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void	fill(char **tab, t_point size, int row, int col, char target)
{

	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] != target || tab[row][col] == 'F')
		return ;
	tab[row][col] = 'F';
	fill(tab, size, row + 1, col, target);
	fill(tab, size, row - 1, col, target);
	fill(tab, size, row, col + 1, target);
	fill(tab, size, row, col - 1, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{

	char	target;

	target = tab[begin.y][begin.x];
	fill(tab, size, begin.y, begin.x, target);
}
