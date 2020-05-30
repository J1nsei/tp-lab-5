//
// Created by Egor on 22.01.2020.
//

#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <string>
#include <vector>

class Student;

class Group
{
public:
    explicit Group(std::string);
    bool AddStudent(Student*);
    void SetHead();
    bool FindStudent(int);
    bool FindStudent(std::string);
    int GetAverageGroupMark();
    bool KickStudent(Student*);
    std::string GetTitle();
    std::string GetHead();

    friend bool Student::AddToGroup(Group* groupToAdd);
    friend class Dean;
private:
    std::string title;
    std::vector<Student*> students;
    Student* head;
};

#endif //TASK1_GROUP_H
