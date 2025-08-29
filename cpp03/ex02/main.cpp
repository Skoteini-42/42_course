#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== CONSTRUCTORS TEST ===\n" << std::endl;

    ClapTrap clap("Clappy");
    ScavTrap scav("Scavy"); 
    FragTrap frag("Fraggy");

    std::cout << "\n=== TEST CLAPTRAP===\n" << std::endl;
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== TEST SCAVTRAP===\n" << std::endl;
    scav.attack("intruder");
    scav.guardGate();
    scav.takeDamage(25);

    std::cout << "\n=== TEST FRAGTRAP===\n" << std::endl;
    frag.attack("target");
    frag.highFivesGuys();
    frag.takeDamage(40);

    std::cout << "\n=== TEST COPY AND ASSIGNMENT ===\n" << std::endl;
    FragTrap fragCopy(frag);
    FragTrap fragAssign("Temp");
    fragAssign = frag;

    std::cout << "\n=== TEST DESCTRUCTORS ===\n" << std::endl;

    return (0);
}
