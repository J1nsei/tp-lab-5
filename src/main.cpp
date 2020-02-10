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
    Dean* dean = new Dean();
    cout <<dean->Get_students().size();
    Group* group = dean->Get_groups()[0];
    vector<Student*>students = group->Get_students();
    cout << students.size() << endl;
    group->Exclusion_student(1);
    students = group->Get_students();
    cout << students.size() << endl;
    delete dean;

}

