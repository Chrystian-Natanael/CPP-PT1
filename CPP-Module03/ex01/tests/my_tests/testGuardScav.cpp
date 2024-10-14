#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

class ScavTrapGuardGateTest : public ::testing::Test {
protected:
	ScavTrap scavtrap;

	std::string captureOutput(std::function<void()> func) {
		std::stringstream buffer;
		std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
		func();
		std::cout.rdbuf(prevcoutbuf);
		return buffer.str();
	}

	virtual void SetUp() {
		scavtrap.setName("TestScavTrap");
	}
};

TEST_F(ScavTrapGuardGateTest, GuardGate) {
	std::string output = captureOutput([&]() {
		scavtrap.guardGate();
	});
	EXPECT_EQ(output, "ScavTrap is now in Gate Keeper Mode.\n");
}
