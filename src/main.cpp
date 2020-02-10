

#include "mainInc.h"

using namespace std;
using namespace rapidjson;

int main()
{
    Deanery dear;
    dear.createGroup("IT10", "Inform");
    dear.findGroup("IT10")->addStudent(new Student("Pidora", 228));
    dear.findGroup("IT10")->addStudent(new Student("Pidor2a", 229));
    dear.addRandomMarks();
    dear.setHeads();
    dear.findGroup("IT10")->printStList();
    dear.resetIds();
    dear.findGroup("IT10")->deleteStudent(dear.findGroup("IT10")->getHead());
    dear.findGroup("IT10")->printStList();
    return 0;
}
