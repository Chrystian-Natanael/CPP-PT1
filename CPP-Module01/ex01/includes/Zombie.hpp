#ifndef ZOMBIES_HPP
#define ZOMBIES_HPP

# include <string>
# include <iostream>

class Zombie {
private:
	std::string	_name;

public:
	void		announce(void);
	void		setName(std::string name);
	std::string	getName(void);

	Zombie(void);
	~Zombie(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif // ZOMBIES_HPP