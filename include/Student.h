#ifndef STUDENT_H
#define STUDENT_H 

#include "common_includes.h"

class Group;
class Student
{
private:
    unsigned int ID;
    std::string fio;
    Group* group;
    std::vector<int> marks;
public:
    Student(int id, std::string full_name);
    ~Student();
};

#endif // SUDENT_H