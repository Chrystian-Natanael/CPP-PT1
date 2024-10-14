#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

class ScavTrapConstructorDestructorTest : public ::testing::Test {
protected:
	std::stringstream output;
	std::streambuf* prevcoutbuf;

	virtual void SetUp() {
		prevcoutbuf = std::cout.rdbuf(output.rdbuf());
	}

	virtual void TearDown() {
		std::cout.rdbuf(prevcoutbuf);
	}

public:
	std::string getOutput() {
		return output.str();
	}
};

TEST_F(ScavTrapConstructorDestructorTest, DefaultConstructor) {
	{
		ScavTrap scavtrap;
	}
	EXPECT_EQ(getOutput(), "ClapTrap constructor called.\nScavTrap constructor called.\nScavTrap destructor called.\nClapTrap destructor called.\n");
}

TEST_F(ScavTrapConstructorDestructorTest, NamedConstructor) {
	{
		ScavTrap scavtrap("TestScavTrap");
	}
	EXPECT_EQ(getOutput(), "ClapTrap constructor called.\nScavTrap constructor called.\nScavTrap destructor called.\nClapTrap destructor called.\n");
}

TEST_F(ScavTrapConstructorDestructorTest, CopyConstructor) {
	ScavTrap scavtrap1("TestScavTrap");
	{
		ScavTrap scavtrap2(scavtrap1);
	}
	EXPECT_EQ(getOutput(), "ClapTrap constructor called.\nScavTrap constructor called.\nClapTrap copy constructor called\nClapTrap assignment operator called\nScavTrap copy constructor called.\nScavTrap assignment constructor called.\nScavTrap destructor called.\nClapTrap destructor called.\n");
}

TEST_F(ScavTrapConstructorDestructorTest, AssignmentOperator) {
	ScavTrap scavtrap1("TestScavTrap");
	ScavTrap scavtrap2;
	{
		scavtrap2 = scavtrap1;
	}
	EXPECT_EQ(getOutput(), "ClapTrap constructor called.\nScavTrap constructor called.\nClapTrap constructor called.\nScavTrap constructor called.\nScavTrap assignment constructor called.\n");
}
