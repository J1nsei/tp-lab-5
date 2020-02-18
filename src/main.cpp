#include "Deanery.h"
#include "Group.h"

int main() {
    auto* deanery = new Deanery();
    deanery->getActualDataFromFile();
    deanery->showAllStudents();
    for (int i = 0; i < 10; i++) {
        deanery->addRandomMarkForAllStudents();
    }
    deanery->showStatisticForAllStudents();

    deanery->startRandomElection();
    deanery->kickStudentWithMarkLowerThan(2);
    deanery->showStatisticForAllStudents();
    deanery->showGroupsHeads();

    deanery->transfer(20, "18-1", "Software");
    deanery->transfer(22, "18-1", "Software");
    deanery->showStatisticForAllStudents();

    deanery->saveData();

    return 0;
}
