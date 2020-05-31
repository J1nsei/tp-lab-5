#ifndef Deanery_h
#define Deanery_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "Student.h"
#include "Group.h"

class Deanery{
private:
    std::string filenameStudents = "Students.txt";
    std::string filenameGroups = "Groups.txt";
    std::vector<Group*> groups;
public:
    Deanery();
    void setDataGroups(); // создание групп на основе данных из файла
    void setDataStudents(); // создание студентов на основе данных из файла
    void addRandomMarks(); // добавление случайных оценок студентам
    void getStatistics(); // получение статистики по успеваемости студентов и групп
    void moveStudent(std::string fio, std::string groupTitle); // перевод студентов из группы в группу
    void dropStudents(); // отчисление студентов за неуспеваемость
    void electHead(); // инициация выборов старост в группах
    void showData(); // вывод данных на консоль
    void saveData(); // сохравнение данных в файл
    std::vector<Group*> getGroups();
    void setGroups();
    void updateGroups(Group* group);
};

#endif /* Deanery_h */
