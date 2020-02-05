//
// Created by Mikhail on 16.01.2020.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
//#include <windows.h>
#include <dean.h>

using namespace std;

int main(){
  //  SetConsoleOutputCP(CP_UTF8);
    auto dean = new Dean();

    for(int i = 0; i < 10; i++) {
        dean->addMarks();
    }
    dean->pickHeads();
    dean->deduction();
    dean->printData();
}