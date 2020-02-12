

#include "mainInc.h"

using namespace std;
using namespace rapidjson;

int main()
{
    Deanery dear;
    dear.createGroup("IT10", "Inform");
    dear.findGroup("IT10")->addStudent(new Student("stName", 228));
    dear.findGroup("IT10")->addStudent(new Student("stName2", 229));
    Group* temp = dear.findGroup("IT10");
    temp->deleteStudent(temp->findStudent("stName"));
    temp->deleteStudent(temp->findStudent("stName"));
    return 0;
}
