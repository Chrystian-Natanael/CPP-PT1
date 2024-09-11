#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon), _name(name) {}

HumanA::~HumanA(void) {}

void	HumanA::setName(const std::string &name) {
	this->_name = name;
}

const std::string	&HumanA::getName(void) {
	return (this->_name);
}

void	HumanA::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}

const std::string	&HumanA::getWeapon(void) {
	return (this->_weapon.getType());
}

void	HumanA::attack(void) {
	std::cout << this->getName() << " attacks with their " << this->getWeapon() << std::endl;
}
