#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	Weapon &_weapon;
	std::string _name;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void setName(const std::string& name);
	const std::string& getName();
	void setWeapon(Weapon weapon);
	const std::string& getWeapon();
	void attack();
};

#endif