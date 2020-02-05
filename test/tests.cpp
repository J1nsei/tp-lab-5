#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST(testStudent, init) {
Student S1;
S1.create("Maxim",1);
EXPECT_EQ("Maxim", S1.getName());
}