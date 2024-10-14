#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

class ClapTrapTest : public ::testing::Test {
protected:
	class TestableClapTrap : public ClapTrap {
	public:
		using ClapTrap::messages;
	};

	TestableClapTrap claptrap;

	std::string captureOutput(std::function<void()> func) {
		std::stringstream buffer;
		std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
		func();
		std::cout.rdbuf(prevcoutbuf);
		return buffer.str();
	}

	 void testMessages(ClapTrap::status type) {
		claptrap.messages(type);
	}

	virtual void SetUp() {
		claptrap.setName("TestBot");
	}
};

TEST_F(ClapTrapTest, MessageWhenDead) {
	std::string output = captureOutput([&]() {
		claptrap.messages(ClapTrap::DEAD);
	});
	EXPECT_EQ(output, "ClapTrap TestBot is already dead.\n");
}

TEST_F(ClapTrapTest, MessageWhenOutOfEnergy) {
	std::string output = captureOutput([&]() {
		claptrap.messages(ClapTrap::ENERGY);
	});
	EXPECT_EQ(output, "ClapTrap TestBot is out of energy.\n");
}

TEST_F(ClapTrapTest, MessageWhenTakesDamage) {
	std::string output = captureOutput([&]() {
		claptrap.messages(ClapTrap::DAMAGE);
	});
	EXPECT_EQ(output, "ClapTrap TestBot is dead.\n");
}

TEST_F(ClapTrapTest, MessageWhenNegativeDamage) {
	std::string output = captureOutput([&]() {
		claptrap.messages(ClapTrap::NEG_DMG);
	});
	EXPECT_EQ(output, "ClapTrap TestBot can't take a negative damage... imo.\n");
}

TEST_F(ClapTrapTest, MessageWhenEmptyAttack) {
	std::string output = captureOutput([&]() {
		claptrap.messages(ClapTrap::EMPTY_ATK);
	});
	EXPECT_EQ(output, "ClapTrap TestBot does no kill ghosts... yet.\n");
}

TEST_F(ClapTrapTest, MessageWhenNegativeRepair) {
	std::string output = captureOutput([&]() {
		claptrap.messages(ClapTrap::NEG_AMOUNT);
	});
	EXPECT_EQ(output, "ClapTrap TestBot can't repair a negative value... dyk?\n");
}
