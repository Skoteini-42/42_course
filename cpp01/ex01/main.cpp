#include "Zombie.hpp"

int main()
{
	int	hordeSize = 10;
	std::string zombieName = "HordeZombie";

    Zombie* horde = zombieHorde(hordeSize, zombieName);
	for (int i = 0; i < hordeSize; i++)
    	horde[i].announce();
    delete[] horde;
    return (0);
}
