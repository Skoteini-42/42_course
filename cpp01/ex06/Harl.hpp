#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{

	private:

	void	debug();
	void	info();
	void	warning();
	void	error();

	int	getLevelIndex(std::string level);

	public:

	void	complain(std::string level);
};

#endif
