#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <cstdlib>
#include "Student.h"

class Group {
private:

    std::string title;
    std::string spec;
    std::vector<class Student *> students;
    Student *head;

public:

    Group(std::string title, std::string spec);

    std::string getTitle();

    std::string getSpec();

    Student *getHead();

    bool setHead(int id, std::string fio);

    bool setHead();

    std::vector<class Student *> getStudents();

    Student *getStudentById(int id);

    Student *getStudentByFio(std::string fio);

    double getAverageMark();

    void addStudent(class Student *student);

    void kickStudent(Student *student);

    void kickStudent(int id);

    void kickStudent(std::string fio);

};
#endif //GROUP_H
