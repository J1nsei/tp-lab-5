#ifndef UNTITLED_DEANERY_H
#define UNTITLED_DEANERY_H


#include "Group.h"

class Deanery {
private:
    Group groups;

public:
    void importStudents(string name, auto g = 0);
    void importGroup(string name, string groupName);
    void addRandomMark();
    void getStatistic();
    void transfer(int id, string tq, string t2);
    void exclude();
    void exportData(string name="example.txt");
    void takeHeaders();
    void printData();
    int stringToInt(string word);

};


#endif //UNTITLED_DEANERY_H
