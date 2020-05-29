#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST(testStudent, init) {
Student student1(255, "Joe Strummer");
EXPECT_EQ(255, student1.getId());
EXPECT_EQ("Joe Strummer", student1.getFio());
}
