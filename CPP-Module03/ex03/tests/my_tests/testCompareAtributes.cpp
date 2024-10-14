#include <gtest/gtest.h>
#include "DiamondTrap.hpp"

class DiamondTrapAttributesTest : public ::testing::Test {
protected:
	DiamondTrap diamondTrap;

	void SetUp() {
		diamondTrap = DiamondTrap("TestDiamond");
	}
};

TEST_F(DiamondTrapAttributesTest, HitPointsFromFragTrap) {
	EXPECT_EQ(diamondTrap.getHitPoints(), 100);
}

TEST_F(DiamondTrapAttributesTest, EnergyPointsFromScavTrap) {
	EXPECT_EQ(diamondTrap.getEnergypoint(), 50);
}

TEST_F(DiamondTrapAttributesTest, AttackDamageFromFragTrap) {
	EXPECT_EQ(diamondTrap.getAttackDamage(), 30);
}
