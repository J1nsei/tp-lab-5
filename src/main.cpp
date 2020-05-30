#include <iostream>
#include <vector>
#include "Deanery.h"
//#include <string>

int main()
{
	system("chcp 1251");

	Deanery* deanery = new Deanery("students.txt");

	//cout << "\n Проверка: " << deanery->small_check() << "\n";
	deanery->add_marks();
	deanery->out_data_in_consol();

	//cout << deanery->get_average_mark_student(8) << endl;
	//cout << deanery->get_average_mark_Group("20ПМИ-1") << endl;

	deanery->transmit_student(deanery->groups[0], deanery->groups[2], 0);
	deanery->transmit_student(deanery->groups[3], 1);
	deanery->add_marks();

	//deanery->out_data_in_consol();

	deanery->remove_student();
	deanery->choose_head_();

	//deanery->out_data_in_consol();
	//deanery->out_data_in_consol();

	deanery->save_data("DATA.txt");

	//Student* st = deanery->make_student("Пак Чи Мин");
	deanery->add_student(deanery->groups[1], deanery->make_student("Пак Чи Мин"));

	deanery->out_data_in_consol();

	return 0;
}
