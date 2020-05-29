#include <vector>
#include <istream>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Dean.h"

Dean::Dean()
{
    idForNewStudent = 1;
}

void Dean::createGroup(std::string _name, std::string _specialty){
    groups.emplace_back(Group(_name, _specialty));
}

void Dean::startCourse(std::istream & stream_students, std::istream & stream_groups){
    std::string s_group, s_spec;
    while (std::getline(stream_groups, s_group, ':')){
        std::getline(stream_groups, s_spec);
        createGroup(s_group, s_spec);
    }
    std::string s_student;
    while (std::getline(stream_students, s_student, ':')){
        std::getline(stream_students, s_group);
        for (auto & x : groups){
            if (x.getName() == s_group){
                Student student = Student(idForNewStudent++, s_student, x.getPointerGroup());
                x.addStudent(student);
            }
        }
    }
}


void Dean::transferStudent(Group& toGroup, Student& student){
    toGroup.addStudent(student);
    student.group->deleteStudent(student);
}

void Dean::expel(Student& student){
    student.group->deleteStudent(student);
}

std::vector<Group> Dean::getGroups() const{
    return groups;
}

std::string Dean::addStudent(std::string name){
    int smallestGroupSize = 10000;

    int smallestGroup = 0;
    for(int i = 0; i < groups.size(); i++){
        if(groups[i].getSize() < smallestGroupSize) {
            smallestGroup = i;
            smallestGroupSize = groups[i].getSize();
        }
    }
    groups[smallestGroup].addStudent (Student(idForNewStudent, name, &groups[smallestGroup]));
    idForNewStudent++;
    return groups[smallestGroup].getName();
}

int Dean::testStudents()
{
    int studentsTested = 0;
    for(Group & group : groups)
    {
        for(Student & student : group.students)
        {
            student.addMark(rand() % 10 + 1);
            ++studentsTested;
        }
    }
    return studentsTested;
}

void Dean::clearing(int minPoint)
{
    for (Group& group : groups)
    {
        auto students = group.students;
        for (Student student : students)
        {
            int averPoint = student.gradePointAverage();
            if(averPoint < minPoint)
            {
                expel(student);
            }
        }
    }
}

