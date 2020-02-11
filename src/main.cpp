//
// Created by Mary on 18.01.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "dean.h"
using namespace std;
int main(){/*
    SetConsoleOutputCP(CP_UTF8);
    string line;
    vector < vector<string> > students(4);
    for (int i = 1; i <= 4; i ++){
        string path = "C:\\Users\\Mary\\CLionProjects\\tp-lab-5\\res\\";
        path += '0' + i;
        path += ".txt";
        cout << path << endl;
        ifstream in(path);
        if (in.is_open()){
            while (getline(in, line)){
                cout << line << endl;
                students[i-1].push_back(line);
            }
        }
        in.close();
    }*/
SetConsoleOutputCP(CP_UTF8);
Dean dean;
dean.createGroups();
dean.generateStudents();
dean.addMarks(3);
dean.printStudents();
dean.getStatistics();
dean.setHeads();
dean.fireStudents();
dean.printStudents();
return 0;
}
