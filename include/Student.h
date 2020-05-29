#ifndef STUDENT_H
#define STUDENT_H
#include "mainInc.h"

using namespace std;

class Group;// см лекцию
class Student
{
    private:
        int id;
        string fio;
        Group* group;
        vector<int> marks;
    public:
        Student();
        Student(string name, int id);
        void setGroup(Group* group){this->group = group;};
        void addMark(int mark){this->marks.push_back(mark);};
        int getMidMark();

        string getName(){return this->fio;};
        unsigned int getId(){return this->id;};
        Group* getGroup(){return this->group;};
        void setId(int id){this->id = id;};

};

#endif // STUDENT_H
