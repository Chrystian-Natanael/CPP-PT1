#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>


class ClapTrap {
public:
enum status { DEAD, ENERGY, DAMAGE, NEG_DMG, EMPTY_ATK, NEG_AMOUNT };

	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergypoint(void) const;
	unsigned int getAttackDamage(void) const;
	void setName(const std::string name);
	void setHitPoints(unsigned int hp);
	void setEnergyPoint(unsigned int ep);
	void setAttackDamage(unsigned int atk);

private:
	std::string		_name;
	unsigned int	_energyPoints;
	unsigned int	_hitPoints;
	unsigned int	_attackDamage;

protected:
	void messages(status type) const;
};

#endif // !CLAPTRAP_HPP