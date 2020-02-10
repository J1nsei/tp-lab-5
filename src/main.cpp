// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Student.h"
#include "Group.h"
#include "Dean.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


using namespace std;

int main()
{
	//setlocale(LC_ALL, "RUS");
	/*Student st1(1,"Igor");
	Student st2(2, "Slava");
	Student st3(3, "Slow");
	
	st1.AddMark(5);
	st1.AddMark(2);
	st1.AddMark(3);
	st1.AddMark(5);
	st2.AddMark(5);
	st2.AddMark(5);
	st2.AddMark(5);
	st2.AddMark(5);
	st3.AddMark(5);
	st3.AddMark(5);
	st3.AddMark(5);
	st3.AddMark(5);
	cout << st1.MiddleMark()<<endl;

	Group gr1("1");
	Group gr2("2");
	gr1.AddStudent(&st1);
	gr2.AddStudent(&st2);
	gr2.AddStudent(&st3);
	gr2.ChooseHead();
	cout << gr2.MiddleGroupMark();
	cout << gr2.findStudentId(2);
	gr2.ExStudent(2);*/

	Deanery number1{};
	number1.CreateGroup();
	number1.AddStudentMark();
	number1.StatisticGroup();
	cout << '\n';
	number1.ReplaceStudent(1, "2", "1");
	cout << '\n';
	cout << '\n';
	cout << '\n';
	number1.ReChooseHeaders("1");
	number1.ReChooseHeaders("2");
	number1.ReChooseHeaders("3");
	number1.DeductStudents();
	number1.Console();
	

	

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
