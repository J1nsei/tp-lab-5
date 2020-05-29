#include <iostream>
#include <string>
#include<fstream>
#include "Student.h"
#include "Group.h"
using namespace std;


int main()
{
	//string fname = "input.txt";
	Deanery hse;

	hse.create_group("PMI", "");
	hse.create_student("Aleksey Navalny", "PMI");
	hse.create_student("Lesha Vishnya", "PMI");

	hse.create_group("PI", "");
	hse.create_student("Vladimir Putin", "PI");
	hse.create_student("Vladimir Solovyev", "PI");
	
	//hse.create_groups_f(fname);

	for (int i = 0; i < 5; ++i) {
		hse.rand_marks();
	}

	hse.rand_marks();
	
	hse.rand_heads();
	Group* obama_new = hse.find_group("PI");
	vector<Student*> founded_new = obama_new->find_name("Vladimir Putin");
	hse.transfer(founded_new[0]->get_id(), "PI", "PMI");

	hse.print_statistics();
	return 0;
}