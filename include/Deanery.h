#ifndef MYLAB5_DEANERY_H
#define MYLAB5_DEANERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "Group.h"
#include "Student.h"

class Deanery {
private:
    std::vector<Group*> groups;

    std::string fileName = "Students.txt";
    void parseStudent(std::string line, std::string *fio, std::string *group, std::string *spec);
    bool isGroupExist(const std::string& title, const std::string& spec);
    Group* getGroupByTitleAndSpec(const std::string& title, const std::string& spec);
public:
    Deanery();
    void getActualDataFromFile();
    void showAllStudents();
    void addRandomMarkForAllStudents();
    void showStatisticForAllStudents();
    void kickStudentWithMarkLowerThan(double lowerBorder);
    void saveData();
    void transfer(int id, const std::string& groupTitle, const std::string& groupSpec);
    void transfer(Student* student, Group* group);
    void startRandomElection();
    void showGroupsHeads();
    std::vector<Group*> getGroups();
};


#endif //MYLAB5_DEANERY_H
