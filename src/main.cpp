#include <iostream>
#include <fstream>
#include <string>
#include "Deanery.h"
#include <time.h>
using namespace std;

int main(){
    system("chcp 65001");
    srand(time(0));
    Deanery* deanery = new Deanery();
    cout<<"___________All_groups___________________"<<endl;
    deanery->AllGroups();
    cout<<"___________GetStatistic_________________"<<endl;
    deanery->GetStatistics();
    cout<<"__________After_ExpelStudent____________"<<endl;
    deanery->ExpelStudent();
    cout<<"__________After_GetStatistics___________"<<endl;
    deanery->GetStatistics();

    return 0;
}