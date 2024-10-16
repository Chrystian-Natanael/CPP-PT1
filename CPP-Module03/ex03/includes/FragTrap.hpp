#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &rhs);

	void attack(const std::string &target);
	void highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP