//
// Created by Egor on 22.01.2020.
//
#include <iostream>
#include <vector>
#include <sstream>
#include "dean.h"
#include "student.h"

using namespace std;

int Student::static_ID = 0;

int main()
{
    system("chcp 65001");
    Dean* dean = new Dean(R"(C:\Users\lacos\Desktop\Coding\C++\tp-lab-5\src\students.txt)");
    dean->ShowStatistics();
    return 0;
}

