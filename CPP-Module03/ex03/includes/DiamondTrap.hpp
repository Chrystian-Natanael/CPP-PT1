#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;
public:

	DiamondTrap(void);
	DiamondTrap(const std::string name);
	DiamondTrap(DiamondTrap const &src);
	~DiamondTrap(void);

	DiamondTrap &operator=(DiamondTrap const &rhs);

	void attack(const std::string &target);
	void whoAmI(void);
};

#endif // !DIAMONDTRAP_HPP