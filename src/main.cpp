#include "student.h"
#include "group.h"
#include "dean.h"

int main()
{
	srand(time(NULL));
	Dean* dean = new Dean();
	dean->create_group("ing.txt");
	dean->create_student("ins.txt");
	dean->add_marks(11);
	dean->check_info();
	//dean->get_S(1)->get_marks();
	dean->to_file();
	dean->expuls();
	dean->moving(dean->get_S(1), dean->get_G(1));
	dean->check_info();
	std::cout << dean->get_G(1)->get_name() << std::endl;
}