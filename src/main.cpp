#include "dean.h"

using namespace std;

int main()
{
    Deanery deanery("../students.txt", "../groups.txt");

    deanery.addStudents();
    deanery.addGroups();
    deanery.electHeadmans();

    deanery.setMarks();
    deanery.setMarks();
    deanery.setMarks();

    deanery.getStatistics();
    deanery.updateData("statistics.txt");

    deanery.printConsole();

    return 0;
}