//
// Created by Sergey Baranenkov on 22.01.2020.
//
#ifndef UNTITLED2_STUDENT_H
#define UNTITLED2_STUDENT_H
#include <vector>

using namespace std;
class Group;
class Student{
private:
    string full_name;
    vector<unsigned int> marks;
    unsigned int id;
    Group* group{};
    Student(unsigned int id, string full_name);

    void add_to_group(Group * group);
    void add_mark(unsigned int mark);
public:
    float get_mean();
    friend class Group;
    friend class Dean;
};


#endif //UNTITLED2_STUDENT_H
