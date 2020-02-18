#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H
#include <string>
#include <vector>
#include <ctime>
#include "Student.h"

class Group {
private:
    std::string title, spec;
    std::vector<class Student*> students;
    Student* head;

public:
    Group(std::string title);
    ~Group();

    std::string getTitle();
    std::string getSpec();
    std::vector<class Student *> getStudents();
    Student *getHead();

    void addStudent(class Student* student);
    void chooseHead();
    Student* getStudent(std::string fio);
    Student* getStudent(int id);
    double getAverageMark();
    void kickStudent(Student* student);
    void kickStudent(int id);
    void kickStudent(std::string fio);
};


#endif