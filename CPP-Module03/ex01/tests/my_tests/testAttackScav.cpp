#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

class ScavTrapAttackTest : public ::testing::Test {
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
		scavtrap.setHitPoints(100);
		scavtrap.setEnergyPoint(50);
		scavtrap.setAttackDamage(20);
	}
};

TEST_F(ScavTrapAttackTest, AttackWithValidTarget) {
	std::string target = "EnemyBot";
	std::string output = captureOutput([&]() {
		scavtrap.attack(target);
	});
	EXPECT_EQ(output, "ScavTrap TestScavTrap attacks EnemyBot, causing 20 points of damage!\n");
	EXPECT_EQ(scavtrap.getEnergypoint(), 49);
}

TEST_F(ScavTrapAttackTest, AttackWithNoEnergy) {
	scavtrap.setEnergyPoint(0);
	std::string output = captureOutput([&]() {
		scavtrap.attack("EnemyBot");
	});
	EXPECT_EQ(output, "ScavTrap TestScavTrap is out of energy.\n");
}

TEST_F(ScavTrapAttackTest, AttackWithEmptyTarget) {
	std::string output = captureOutput([&]() {
		scavtrap.attack("");
	});
	EXPECT_EQ(output, "ClapTrap TestScavTrap does no kill ghosts... yet.\n");
	EXPECT_EQ(scavtrap.getEnergypoint(), 50);
}
