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
    size_t findByName(std::string name) const;
    size_t findByID(unsigned int id) const;
    void estimate(unsigned int id);
    int findMean() const;
    void exclude(unsigned int id);
    ~Group();
};

#endif // GROUP_H