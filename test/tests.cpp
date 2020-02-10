#include "gtest/gtest.h"
#include <Dean.h>

TEST(task1, task1_1) {
Dean* dean = new Dean();
EXPECT_EQ(93, dean->Get_students().size());
delete dean;
}

TEST(task1, task1_2) {
Dean* dean = new Dean();
EXPECT_EQ(5, dean->Get_groups().size());
delete dean;
}