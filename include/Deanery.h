//
// Created by aklen on 28.01.2020.
//
#include <iostream>
#include <string>
#include <Group.h>
using namespace std;

class Group;
class Student;

class Deanery{
private:
    vector<Group*> groups;
public:
    bool isGroupExist(string);
    explicit Deanery();
    void addRandomMarksToStudents();
    void getStatistics();
    bool removeStudent(Group* ,Group* , int);
    void checkForKick();
    void rewriteDataFile(string);
    void changeHeads();
    void consoleOutPut();
    void listOfGroups();
};


