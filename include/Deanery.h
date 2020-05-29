#pragma once
#include "Group.h"
#include <string>
class Deanery {
private:
	vector<Group*> groups;
	void CreateStudents(string fn, Group* group);
public:
	void CreateGroups(string fn);
	void AddRandMarks(int num);//добавление случайных оценок студентам
	void PrintStat();//статистикa по успеваемости студентов и групп
	void Transf(string fio, string title1, string title2);//перевод студентов из группы в группу
	void Expulsion(double points);//отчисление студентов за неуспеваемость
	void SaveData();//сохранение обновленных данных в файлах
	void ChooseHead();//инициация выборов старост в группах
	void PrintData();//вывод данных на консоль
};