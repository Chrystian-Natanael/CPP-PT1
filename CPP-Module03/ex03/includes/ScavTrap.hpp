#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:

	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(const std::string &target);
	void guardGate();
};

#endif // !SCAVTRAP_HPP