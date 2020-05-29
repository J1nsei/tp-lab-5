#pragma once
#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"

using namespace std;

class Deanery
{
private:
    string name;
    vector<Group> groups;
public:
    Deanery(const string name);
    void addGroup(const Group& newGroup);
    void inputData(const string& fileName);
    Group* findGroup(const string& name);
    void addMarks(const string& groupName, size_t number);
    ostream& getStudentStatistic(ostream& out, const string& studentId, const string& groupName);
    ostream& getGroupStatistic(ostream& out, const string& groupName);
    void trasnferStudent(const string& studentId, const string& curGroup, const string& newGroup);
    void mountPurge();
    void saveData(const string fileName);
    void electHeads();

    string getName() const;
    size_t getNumberOfGroups() const;
    void printDeanery(ostream& out);
};