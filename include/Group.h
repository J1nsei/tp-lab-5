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
    Group(std::string title, std::string spec);
    void addStudent(Student* student);
    void electionOfHead();
    int findByName(std::string name) const;
    int findByID(unsigned int id) const;
    void estimate(unsigned int id);
    int findMean() const;
    void exclude(unsigned int id);
    ~Group();
};

#endif // GROUP_H