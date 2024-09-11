#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	Zombie zombie;
	Zombie *zombieJr = newZombie("Jack Jackson");

	zombie.setName("Michael Jackson");
	zombie.announce();

	randomChump("Junior Jackson");

	zombieJr->announce();

	delete zombieJr;
	return (EXIT_SUCCESS);
}