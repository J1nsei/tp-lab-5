#ifndef UNTITLED_DEANERY_H
#define UNTITLED_DEANERY_H


#include "Group.h"
#include "Student.h"

class Deanery {
private:
    vector<Group*> groups;
    int stringToInt(tring word);

public:
    Deanery();
    void importFile(string name, string group="", string groupSpec="");
    void addGroup(Group* g);
    void addRandomMarks();
    void getStatistic();
    void transfer(int id, string gTitle1, string gTitle2);
    void exclude();
    void exportData(string name="example.txt");
    void takeHeaders();
    void printData();

};


#endif //UNTITLED_DEANERY_H
