#pragma once
#include <string> 
#include <vector>
#include "Student.h"
using namespace std;

class Group
{
private:
    string title;
    string spec;
    vector<Student*>students;
    Student* head;

public:
    friend class Deanery;
    Group(string title_);
    void AddStudent(Student* Student_);
    Student* ChosHead();
    Student* SearshStud(int id_);
    double MediumMarkG();
    void DeleteStud(int id_);
    int GetSize();
    
};
