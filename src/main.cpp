#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include "Dean.h"
#include "Group.h"
#include "Student.h"

using namespace std;

int main(){
	//SetConsoleOutputCP(65001);
	//SetConsoleCP(1251);
	//setlocale(LC_ALL, "Russian_Russia.1251");
	//SetConsoleOutputCP(1251);
	system("chcp 1251");
	string filename = "student1.txt";
	Dean file(filename);

	file.add_random_marks("17ПИ-1", 7);
	file.add_random_marks("18ПМИ-2", 8);
	file.add_random_marks("19БИ-2", 7);
	file.add_random_marks("18ПМИ-1", 9);

	file.choose_head("17ПИ-1");
	cout << "В группе 17ПИ-1 староста:" << file.find_group("17ПИ-1")->get_head().get_name()<<"\n";
	file.choose_head("18ПМИ-2");
	cout << "В группе 18ПМИ-2 староста:" << file.find_group("18ПМИ-2")->get_head().get_name() << "\n";
	file.choose_head("19БИ-2");
	cout << "В группе 19БИ-2 староста:" << file.find_group("19БИ-2")->get_head().get_name() << "\n";
    file.choose_head("18ПМИ-1");
	cout << "В группе 18ПМИ-1 староста:" << file.find_group("18ПМИ-1")->get_head().get_name() << "\n";


	cout<<"Количество студентов в группе 19БИ-2 равно "<<file.find_group("19БИ-2")->get_size()<<"\n";
	cout << "Количество студентов в группе 18ПМИ-1 равно " << file.find_group("18ПМИ-1")->get_size() << "\n";
	cout << "Количество студентов в группе 18ПМИ-2 равно " << file.find_group("18ПМИ-2")->get_size() << "\n";
	cout << "Количество студентов в группе 17ПИ-1 равно " << file.find_group("17ПИ-1")->get_size() << "\n";

	file.data_output("output1.txt");

    file.find_group("19БИ-2")->search_Student("Хованский Савелий Остапович");
	file.transfer_student("Аглеев Олег Чеславович", "18ПМИ-2", "19БИ-2"); 
	file.check_delete_students();

	file.data_output("output2.txt");
}



