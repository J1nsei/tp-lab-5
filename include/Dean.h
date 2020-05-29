#pragma once

class Group;
class Student;
class Dean{
private:
    std::vector<Group> groups;
    int idForNewStudent;
public:
    Dean();
    void createGroup(std::string _name, std::string _specialty);
    void transferStudent(Group& toGroup, Student& student);
    void expel(Student& student);
    std::vector<Group> getGroups() const;
    void startCourse(std::istream & stream_students, std::istream & stream_groups);
    std::string addStudent(std::string name);
    int testStudents();
    void clearing(int minPoint);
};