//
// Created by aklen on 15.01.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Deanery.h"
#include <time.h>
using namespace std;

int main(){
    srand(time(0));
    Deanery* new_dean = new Deanery();
    cout<<"----------------"<<endl;
    new_dean->getStatistics();
    cout<<"-----------------------------------------------------------------------"<<endl;
    new_dean->checkForKick();
    new_dean->getStatistics();
    new_dean->listOfGroups();
    return 0;
}
