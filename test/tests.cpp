#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Dean.h"

TEST(lab5, test1) {
	Dean* dean = new Dean("students.csv");
	dean->createGroups();
	Group* group = dean->findGroupByName("18PI-2");
	EXPECT_EQ("18PI-2", group->getName());
}
