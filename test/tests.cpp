#include "gtest/gtest.h"
#include "Dean.h"
#include <string>

TEST(testDean, init) {
	std::string s;
	Dean *dean = new Dean();
	dean->create_group("ing.txt");
	dean->create_student("ins.txt");
	dean->add_marks(11);
	s=dean->get_G(1)->get_name();
	EXPECT_EQ("gr2", s);
}