#ifndef DECKANAT_H
#define DECKANAT_H
#include "mainInc.h"
#include "rapidjson/prettywriter.h"
using namespace std;

class Deanery
{
    public:
        Deanery();
        vector<Group*> getGroupList(){return this->groups;};
        void parseJson(string jsonFileName);
        Group* findGroup(string grName);
        void changeStGroup(Student* st, Group* newGroup);
        void setHeads();
        void createJson(string jsonFileName);
        void addRandomMarks();
        void deleteAllBadStudents();
        int recieveStats(Group* group);
        int recieveStats(Student* student);
        void createGroup(string name, string spec);
        void resetIds();
    private:
        vector<Group*>groups;
        int studentCount;
};

#endif // DECKANAT_H
