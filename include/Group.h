#ifndef Group_h
#define Group_h

#include <stdio.h>
#include "Student.h"
#include <vector>
#include <string>

class Student;
class Group {
private:
    std::string title; // название группы
    std::string spec; // специальность
    std::vector<Student*> students; // вектор ссылок на студентов
    Student* head; // ссылка на старосту (из членов группы)
public:
    Group(std::string title, std::string spec); // создание группы с указанием названия
    void addStudent(Student* student); // добавление студента
    void changeHead(Student* head); // избрание старосты
    Student* findStudentByID(int id); // поиск студента по ИД
    Student* findStudentByName(std::string fio); // поиск студента по имени
    float getAverageMark(); // вычисление соеднего балла в группе
    void deleteStudent(int id); // исключение студента из группы
    std::string getTitle();
    std::string getSpec();
    Student* getHead();
    std::vector<Student*> getStudents();
};
#endif
