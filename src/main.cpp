#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "student.h"
#include "group.h"
#include "deanery.h"


int main()
{
	Deanery* dean = new Deanery();
	dean->add_groups("names.txt", "groups.txt");
	dean->elect_heads();
	dean->set_marks(6);
	std::cout << "************************ Statistics ************************" << std::endl;
	dean->get_stat();
	
	dean->allocations();
	std::cout << "************************ Statistics ************************" << std::endl;
	dean->get_stat();
	dean->save_data("names_.txt", "groups_.txt");

	getchar();

}