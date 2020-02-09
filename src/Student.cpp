#include <vector>
#include <string>
#include <cmath>
#include "Student.h"
#include "Group.h"

Student::Student(const int& _id, const std::string& _name, Group* _group){
    id = _id;
    name = _name;
    group = _group;
}



int Student::gradePointAverage() const {
    double sum = 0;
    for (const auto & x : marks)
        sum += x;
    return round(sum / double(marks.size()));
}

int Student::getId() const{
    return id;
}

std::string Student::getName() const{
    return name;
}

Group* Student::getGroup() const{
    return group;
}

std::vector<int> Student::getMarks() const{
    return marks;
}

bool operator==(const Student & a, const Student & b){
    return a.id == b.id;
}

void Student::addMark(int mark)
{
    marks.push_back(mark);
}
