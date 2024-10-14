#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap constructor called.\n";
	this->setHitPoints(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called.\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called.\n";
	this->setHitPoints(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called.\n";
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap assignment constructor called.\n";
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoint(rhs.getEnergypoint());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (!this->getEnergypoint()) {
		std::cout << "ScavTrap " << getName() << " is out of energy." << std::endl;
		return ;
	}
	if (target.empty()) {
		messages(EMPTY_ATK);
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(this->getEnergypoint() - 1);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate Keeper Mode." << std::endl;
}
