#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

class ClapTrapAttackTest : public ::testing::Test {
protected:
	ClapTrap claptrap;

	std::string captureOutput(std::function<void()> func) {
		std::stringstream buffer;
		std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
		func();
		std::cout.rdbuf(prevcoutbuf);
		return buffer.str();
	}

	virtual void SetUp() {
		claptrap.setName("TestBot");
		claptrap.setEnergyPoint(5);
	}
};

TEST_F(ClapTrapAttackTest, AttackWithValidTarget) {
	std::string target = "EnemyBot";
	std::string output = captureOutput([&]() {
		claptrap.attack(target);
	});
	EXPECT_EQ(output, "ClapTrap TestBot attacks EnemyBot, causing 0 points of damage!\n");
	EXPECT_EQ(claptrap.getEnergypoint(), 4);
}

TEST_F(ClapTrapAttackTest, AttackWithNoEnergy) {
	claptrap.setEnergyPoint(0);
	std::string output = captureOutput([&]() {
		claptrap.attack("EnemyBot");
	});
	EXPECT_EQ(output, "ClapTrap TestBot is out of energy.\n");
	EXPECT_EQ(claptrap.getEnergypoint(), 0);
}

TEST_F(ClapTrapAttackTest, AttackWithEmptyTarget) {
	std::string output = captureOutput([&]() {
		claptrap.attack("");
	});
	EXPECT_EQ(output, "ClapTrap TestBot does no kill ghosts... yet.\n");
	EXPECT_EQ(claptrap.getEnergypoint(), 5);
}
