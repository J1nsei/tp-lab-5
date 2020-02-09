#include <vector>
#include <string>
#include "Group.h"
#include "Student.h"
void Group::addStudent(Student _student){
    students.push_back(_student);
}
Group* Group::getPointerGroup()
{
    return this;
}

void Group::deleteStudent(Student _student){
    int i = 0;
    for(Student student : students)
    {
        if(student.getId() == _student.getId())
        {
            students.erase(students.begin() + i);
            break;
        }
        ++i;
    }
}

Group::Group(std::string _name, std::string _speciality){
    name = _name;
    specialty = _speciality;
    headman = nullptr;
}

void Group::newHeadman(){
    headman = &students[rand() % students.size()];
}

std::string  Group::getName() const{
    return name;
}

std::string Group::getSpecialty() const{
    return specialty;
}

std::vector<Student> Group::getStudents() const{
    return students;
}

Student* Group::getHeadman() const{
    return headman;
}

int Group::getSize()
{
    return students.size();
}
