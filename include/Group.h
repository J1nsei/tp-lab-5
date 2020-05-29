#pragma once
class Student;
class Dean;
class Group{
private:
    std::string name;
    std::string specialty;
    std::vector<Student> students;
    Student* headman;
    void addStudent(Student _student);
    void deleteStudent(Student _student);
    Group* getPointerGroup();
public:
    Group(std::string _name, std::string _speciality);
    void newHeadman();
    std::string getName() const;
    std::string getSpecialty() const;
    std::vector<Student> getStudents() const;
    Student* getHeadman() const;
    friend class Dean;
    int getSize();
};