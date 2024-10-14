#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class wrongCat : public wrongAnimal {
public:
	wrongCat();
	wrongCat(wrongCat const &rhs);
	~wrongCat();

	wrongCat &operator=(wrongCat const &rhs);

	void makeSound() const;
};

#endif // !WRONGCAT_HPP