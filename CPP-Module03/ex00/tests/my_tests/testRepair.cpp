#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

class ClapTrapRepairTest : public ::testing::Test {
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
		claptrap.setHitPoints(5);
		claptrap.setEnergyPoint(5);
	}
};

TEST_F(ClapTrapRepairTest, RepairWithPositiveAmount) {
	unsigned int repairAmount = 3;
	std::string output = captureOutput([&]() {
		claptrap.beRepaired(repairAmount);
	});
	EXPECT_EQ(output, "ClapTrap TestBot repaired in 3. Hit points now 8\n");
	EXPECT_EQ(claptrap.getHitPoints(), 8);
	EXPECT_EQ(claptrap.getEnergypoint(), 4);
}

TEST_F(ClapTrapRepairTest, RepairWhenDead) {
	claptrap.setHitPoints(0);
	std::string output = captureOutput([&]() {
		claptrap.beRepaired(5);
	});
	EXPECT_EQ(output, "ClapTrap TestBot is already dead.\n");
	EXPECT_EQ(claptrap.getHitPoints(), 0);
	EXPECT_EQ(claptrap.getEnergypoint(), 5);
}

TEST_F(ClapTrapRepairTest, RepairWithNoEnergy) {
	claptrap.setEnergyPoint(0);
	std::string output = captureOutput([&]() {
		claptrap.beRepaired(5);
	});
	EXPECT_EQ(output, "ClapTrap TestBot is out of energy.\n");
	EXPECT_EQ(claptrap.getHitPoints(), 5);
	EXPECT_EQ(claptrap.getEnergypoint(), 0);
}

TEST_F(ClapTrapRepairTest, RepairWithNegativeAmount) {
	unsigned int repairAmount = static_cast<unsigned int>(-5);
	std::string output = captureOutput([&]() {
		claptrap.beRepaired(repairAmount);
	});
	EXPECT_EQ(output, "ClapTrap TestBot can't repair a negative value... dyk?\n");
	EXPECT_EQ(claptrap.getHitPoints(), 5);
	EXPECT_EQ(claptrap.getEnergypoint(), 5);
}
