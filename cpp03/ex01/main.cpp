#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CONSTRUCTION TEST ===\n" << std::endl;

    ScavTrap scav("Guardian");
    
    std::cout << "\n=== ATTRIBUTES TEST ===\n" << std::endl;
    std::cout << "Name: " << scav.getName() << std::endl;
    std::cout << "Hit Points: " << scav.getHitPoints() << " (should be 100)" << std::endl;
    std::cout << "Energy Points: " << scav.getEnergyPoints() << " (should be 50)" << std::endl;
    std::cout << "Attack Damage: " << scav.getAttackDamage() << " (should be 20)" << std::endl;
    
    std::cout << "\n=== FUNCTIONALITY TEST ===\n" << std::endl;
    
    // Test overridden attack
    scav.attack("an intruder");
    std::cout << "Energy after attack: " << scav.getEnergyPoints() << std::endl;
    
    // Test inherited functions
    scav.takeDamage(30);
    std::cout << "HP after damage: " << scav.getHitPoints() << std::endl;
    
    scav.beRepaired(15);
    std::cout << "HP after repair: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy after repair: " << scav.getEnergyPoints() << std::endl;
    
    // Test special ability
    std::cout << "\n=== SPECIAL ABILITY TEST ===\n" << std::endl;
    scav.guardGate();
    
    std::cout << "\n=== COPY AND ASSIGNMENT TEST ===\n" << std::endl;
    
    // Test copy constructor
    ScavTrap scavCopy(scav);
    std::cout << "Copy name: " << scavCopy.getName() << std::endl;
    std::cout << "Copy HP: " << scavCopy.getHitPoints() << std::endl;
    
    // Test assignment operator
    ScavTrap scavAssigned("Temp");
    std::cout << "Before assignment - Name: " << scavAssigned.getName() << std::endl;
    std::cout << "Before assignment - HP: " << scavAssigned.getHitPoints() << std::endl;
    scavAssigned = scav;
    std::cout << "After assignment - Name: " << scavAssigned.getName() << std::endl;
    std::cout << "After assignment - HP: " << scavAssigned.getHitPoints() << std::endl;
    
    std::cout << "\n=== DESTRUCTION CHAINING ===\n" << std::endl;
    
    return 0;
}
