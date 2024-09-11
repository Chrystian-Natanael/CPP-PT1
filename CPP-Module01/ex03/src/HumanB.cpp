#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL), _name(name) {}

HumanB::~HumanB(void) {}

void	HumanB::setName(const std::string &name) {
	this->_name = name;
}

const std::string	&HumanB::getName(void) {
	return (this->_name);
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

const std::string	&HumanB::getWeapon(void) {
	return (this->_weapon->getType());
}

void	HumanB::attack(void) {
	std::cout << this->getName() << " attacks with their "
		<< (_weapon != NULL ? _weapon->getType() : "hand")
		<< std::endl;
}
