#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

using namespace std;


int main()
{
    Deanery dean1("dean1");
    dean1.inputData("data1.txt");

    dean1.addMarks("18PMI-1", 10);
    dean1.addMarks("18PMI-2", 10);
    dean1.addMarks("18PI-1", 10);
    dean1.addMarks("18PI-2", 10);

    Group* testGroup = dean1.findGroup("18PMI-1");
    if(testGroup)
    {
        cout << "Group has been found"<<endl;
        dean1.getGroupStatistic(cout, "18PMI-1");
    }
    else
    {
        cout << "No such group!"<<endl;
    }
    dean1.trasnferStudent("O’Brien’ Joshua", "18PMI-1", "18PI-2");
   //dean1.mountPurge();
    dean1.printDeanery(cout);
    getchar();
    return 0;
}