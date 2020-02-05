#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST(testStudent, init) {
	Group group("title", "spec");
	EXPECT_EQ("title", group.GetTitle());
}
