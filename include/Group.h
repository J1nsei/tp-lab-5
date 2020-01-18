#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
class Student;
class Group
{
private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
public:
    Group(/* args */);
    ~Group();
};

#endif // GROUP_H