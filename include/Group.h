#ifndef Group_h
#define Group_h

#include <stdio.h>
#include "Student.h"
#include <vector>
#include <string>

using namespace std;

class Student;
class Group {
private:
    string title; // название группы
    string spec; // специальность
    vector<Student*> students = {}; // вектор ссылок на студентов
    Student* head; // ссылка на старосту (из членов группы)
public:
    Group(string title, string spec); // создание группы с указанием названия
    void addStudent(Student* student); // добавление студента
    void changeHead(Student* head); // избрание старосты
    Student* findStudentByID(int id); // поиск студента по ИД
    Student* findStudentByName(string fio); // поиск студента по имени
    float getAverageMark(); // вычисление соеднего балла в группе
    void deleteStudent(int id); // исключение студента из группы
    string getTitle();
    string getSpec();
    Student* getHead();
    vector<Student*> getStudents();
};
#endif
