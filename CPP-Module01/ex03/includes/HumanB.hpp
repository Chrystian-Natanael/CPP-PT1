#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	Weapon *_weapon;
	std::string _name;

public:
	HumanB(std::string name);
	~HumanB(void);

	void setName(const std::string& name);
	const std::string& getName();
	void setWeapon(Weapon &weapon);
	const std::string& getWeapon();
	void attack();
};

#endif