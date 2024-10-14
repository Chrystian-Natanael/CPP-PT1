#include <gtest/gtest.h>
#include "DiamondTrap.hpp"

class DiamondTrapFunctionalityTest : public ::testing::Test {
protected:
	std::stringstream output;
	DiamondTrap diamondTrap;

	void SetUp() {
		diamondTrap = DiamondTrap("TestDiamond");
		std::cout.rdbuf(output.rdbuf());
	}

	std::string getOutput() {
		return output.str();
	}
};

TEST_F(DiamondTrapFunctionalityTest, AttackFunction) {
	diamondTrap.attack("Enemy");

	EXPECT_EQ(getOutput(), 
			  "ScavTrap TestDiamond attacks Enemy, causing 30 points of damage!\n");
	EXPECT_EQ(diamondTrap.getEnergypoint(), 49);
}
