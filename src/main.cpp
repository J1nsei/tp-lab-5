//
// Created by Оксана on 15.01.2020.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
//#include <windows.h>
#include <Dean.h>

using namespace std;

int main(){
    Dean* dean = new Dean();
    cout <<dean->Get_students().size();
    delete dean;

}

