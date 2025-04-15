#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		printf("Error : Invalid number of arguments\n");
		return (1);
	}
	memset(&table, 0, sizeof(t_table));
	if (parse_args(&table, argc, argv) != 0)
		return (1);
	if (initialize_simulation(&table) != 0)
		return (cleanup(&table, "Initialization failed", 1));
	return (cleanup(&table, NULL, 0));
}