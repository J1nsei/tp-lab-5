#ifndef LAB5_DEANERY_H
#define LAB5_DEANERY_H
#include <iostream>
#include <string>
#include "group.h"
using namespace std;

class Group;
class Student;

class Deanery{
private:
    vector<Group*> groups;
public:
    explicit Deanery();

    bool GroupExist(string);
    void AddRandomMarks();
    void GetStatistics();
    bool ChangeGroup(Group* ,Group* , int);
    void ExpelStudent();
    void SaveData(string);
    void ChangeHeads();
    void PrintData();
    void AllGroups();
};
#endif //LAB5_DEANERY_H
