#ifndef Deanery_h
#define Deanery_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "Student.h"
#include "Group.h"

using namespace std;

class Deanery{
private:
    string filenameStudents = "Students.txt";
    string filenameGroups = "Groups.txt";
    vector<Group*> groups;
public:
    Deanery();
    void setDataGroups(); // создание групп на основе данных из файла
    void setDataStudents(); // создание студентов на основе данных из файла
    void addRandomMarks(); // добавление случайных оценок студентам
    void getStatistics(); // получение статистики по успеваемости студентов и групп
    void moveStudent(string fio, string groupTitle); // перевод студентов из группы в группу
    void dropStudents(); // отчисление студентов за неуспеваемость
    void electHead(); // инициация выборов старост в группах
    void showData(); // вывод данных на консоль
    void saveData(); // сохравнение данных в файл
};

#endif /* Deanery_h */
