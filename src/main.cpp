#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Deanery* deanery = new Deanery();
    deanery->setDataGroups();
    deanery->setDataStudents();
    deanery->electHead();
    deanery->addRandomMarks();
    deanery->getStatistics();
    deanery->moveStudent("Лапина Алина Сергеевна", "18ПИ1");
    deanery->dropStudents();
    deanery->getStatistics();
    deanery->showData();
    deanery->saveData();
}
