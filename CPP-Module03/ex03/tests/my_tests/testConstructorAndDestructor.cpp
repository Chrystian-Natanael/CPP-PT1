#include <gtest/gtest.h>
#include "DiamondTrap.hpp"

class DiamondTrapConstructorDestructorTest : public ::testing::Test {
protected:
	std::stringstream output;
	
	void SetUp() {
		std::cout.rdbuf(output.rdbuf());
	}

	std::string getOutput() {
		return output.str();
	}
};

TEST_F(DiamondTrapConstructorDestructorTest, DefaultConstructor) {
	{
		DiamondTrap diamondTrap("TestDiamond");
	}
	EXPECT_EQ(getOutput(), 
			  "ClapTrap constructor called.\n"
			  "ScavTrap constructor called.\n"
			  "FragTrap constructor called.\n"
			  "DiamondTrap constructor called.\n"
			  "DiamondTrap destructor called.\n"
			  "FragTrap destructor called.\n"
			  "ScavTrap destructor called.\n"
			  "ClapTrap destructor called.\n");
}

TEST_F(DiamondTrapConstructorDestructorTest, CopyConstructor) {
	{
		DiamondTrap original("OriginalDiamond");
		DiamondTrap copy(original);
	}
	EXPECT_EQ(getOutput(),
			"ClapTrap constructor called.\n"
			"ScavTrap constructor called.\n"
			"FragTrap constructor called.\n"
			"DiamondTrap constructor called.\n"
			"ClapTrap copy constructor called\n"
			"ClapTrap assignment operator called\n"
			"ScavTrap copy constructor called.\n"
			"ScavTrap assignment constructor called.\n"
			"FragTrap copy constructor called.\n"
			"FragTrap assignment constructor called.\n"
			"DiamondTrap copy constructor called.\n"
			"DiamondTrap assignment constructor called.\n"
			"DiamondTrap destructor called.\n"
			"FragTrap destructor called.\n"
			"ScavTrap destructor called.\n"
			"ClapTrap destructor called.\n"
			"DiamondTrap destructor called.\n"
			"FragTrap destructor called.\n"
			"ScavTrap destructor called.\n"
			"ClapTrap destructor called.\n");
}
