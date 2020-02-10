#include "gtest/gtest.h"

#include "Deanery.h"
#include "Group.h"
#include "Student.h"
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

TEST(deanery, number_of_students1)
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

TEST(deanery, transfer1)
{
	Deanery hse;
	hse.create_group("PMI", "");
	hse.create_student("Aleksey Navalny", "PMI");
	hse.create_student("Lesha Vishnya", "PMI");

	hse.create_group("PI", "");
	hse.create_student("Vladimir Putin", "PI");
	hse.create_student("Vladimir Solovyev", "PI");

	Group* pi = hse.find_group("PI");
	vector<Student*> founded = pi->find_name("Vladimir Putin");
	hse.transfer(founded[0]->get_id(), "PI", "PMI");

	Group* pi_new = hse.find_group("PMI");

	EXPECT_EQ(3 , pi_new.size());
}