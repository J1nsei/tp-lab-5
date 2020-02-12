#ifndef UNTITLED_GROUP_H
#define UNTITLED_GROUP_H


#include <string>
#include <vector>

using namespace std;

class Student;
class Group {
private:
    string title;
    string spec;
    vector<Student*> students;
    Student* head;

public:
    Group(string title, string spec);
    ~Group();
    void addStudent(Student* student);
    void takeHead();
    Student* searchStudent(int id);
    Student* searchStudent(string fio);
    double averageMark();
    void exclude(int id);
    void exclude(string fio);
    string getTitle();
    vector<Student*>& getStudents();
    string getSpec();
    Student* getHead();
};


#endif //UNTITLED_GROUP_H
