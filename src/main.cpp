//
// Created by Оксана on 15.01.2020.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
//#include <windows.h>
#include <Dean.h>
#include <Group.h>
#include "Student.h"

using namespace std;

int main(){

    //SetConsoleOutputCP(65001);


    Dean* dean = new Dean();
    Group* group = dean->Get_groups()[0];
    cout << group->Get_students().size() << endl;
    dean-> Add_marks(group->Get_title(), 7);
    dean->Check_and_delete_students("18FM");
    cout << dean->Get_groups()[0]->Get_students().size() << endl;
    dean->Choose_head("18FM");
    dean->Print_date();
    delete dean;

}

