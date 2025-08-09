#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("ConeheadZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("NewspaperZombie");
    return (0);
}
