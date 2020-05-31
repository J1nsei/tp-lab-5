#include "gtest/gtest.h"
#include"../include/Deanery.h"
#include <string>

TEST(testStudent, init) {
	student student1("Henry Ford", 0);
	EXPECT_EQ(0, student1.getId());
	EXPECT_EQ("Henry Ford", student1.getFio());
}

TEST(testGroup, init) {
	Group group1("18PMI-1", "PMI");
	EXPECT_EQ("18PMI-1",group1.getTitle());
	EXPECT_EQ("PMI",group1.getSpec());
}
