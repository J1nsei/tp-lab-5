//
// Created by Sergey Baranenkov on 22.01.2020.
//

#ifndef UNTITLED2_GROUP_H
#define UNTITLED2_GROUP_H

#include <string>
#include "Student.h"

using namespace std;
class Dean;
class Group{
private:
    string title;
    Student *head{};
    explicit Group(const string& group_name);
    void add_student(Student* student);
    void set_head (Student *);
    Student* kick_student(unsigned int id);
    const Student* find_student(unsigned int id);
    float get_average_score();
    friend class Dean;

public:
    vector <Student*> students;
};


#endif //UNTITLED2_GROUP_H
