#include <gtest/gtest.h>
#include "DiamondTrap.hpp"

class DiamondTrapWhoAmITest : public ::testing::Test {
protected:
	std::stringstream output;
	DiamondTrap diamondTrap;

	void SetUp() override {
		diamondTrap = DiamondTrap("TestDiamond");
		std::cout.rdbuf(output.rdbuf());
	}

	std::string getOutput() {
		return output.str();
	}
};

TEST_F(DiamondTrapWhoAmITest, WhoAmIFunction) {
	diamondTrap.whoAmI();
	
	EXPECT_EQ(getOutput(), 
			"My name is: TestDiamond and ClapTrap name is: TestDiamond_clap_name\n");
}
