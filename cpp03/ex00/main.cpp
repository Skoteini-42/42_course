#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	std::cout << "=== ClapTrap Test ===\n" << std::endl;
    //Default contructor
	std::cout << "Creating default ClapTrap:" << std::endl;
	ClapTrap defaultRobot;
	std::cout << "Default name: " << defaultRobot.getName() << std::endl;
	std::cout << "Default HP: " << defaultRobot.getHitPoints() << std::endl;
	std::cout << "Default energy: " << defaultRobot.getEnergyPoints() << std::endl;
	std::cout << "Default damage: " << defaultRobot.getAttackDamage() << std::endl;
	std::cout << "\n---\n" << std::endl;

	//Create ClapTraps - Contructors with parameters
    ClapTrap robot1("R2D2");
    ClapTrap robot2("C3PO");
    //Test attacks
    robot1.attack("C3PO");
    robot2.attack("R2D2");
    //Test damage and repair
    robot1.takeDamage(5);
    robot1.beRepaired(3);
    //Test energy consumption
    for (int i = 0; i < 5; i++)
	{
        robot2.attack("target");
    }
	//Test destruction
    robot1.takeDamage(10);
    robot1.attack("should fail");
    robot1.beRepaired(5);
    
    std::cout << "\n=== End of test ===\n" << std::endl;
    
    return (0);
}
