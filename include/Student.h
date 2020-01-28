#ifndef STUDENT_H
#define STUDENT_H 

#include "common_includes.h"

class Group;
class Student
{
private:
    unsigned int id;
    std::string fio;
    Group* group;
    std::vector<int> marks;
public:
    Student(int ID, std::string full_name);
    void enroll(Group* group);
    void addMark(int mark);
    int calcMean() const;
    std::string getFIO() const; 
    unsigned int getID() const;
    ~Student();
};

#endif // SUDENT_H