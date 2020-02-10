#include "gtest/gtest.h"

#include "Deanery.h"
#include "Group.h"
#include "Student.h"
#include <vector>
#include <string>

TEST(deanery, number_of_students1)
{
	Deanery hse;
	hse.create_group("PMI", "");
	hse.create_student("Aleksey Navalny", "PMI");
	hse.create_student("Lesha Vishnya", "PMI");

	hse.create_group("PI", "");
	hse.create_student("Vladimir Putin", "PI");
	hse.create_student("Vladimir Solovyev", "PI");

	EXPECT_EQ(4, hse.total_num_of_stud());
}

TEST(deanery, number_of_students2)
{
	Deanery hse;
	hse.create_group("PMI", "");
	hse.create_student("Aleksey Navalny", "PMI");
	hse.create_student("Lesha Vishnya", "PMI");

	hse.create_group("PI", "");
	hse.create_student("Vladimir Putin", "PI");
	hse.create_student("Vladimir Solovyev", "PI");
	hse.expel("PI", 4);

	EXPECT_EQ(3, hse.total_num_of_stud());
}