//
//  main.cpp
//  Shtanyuk5
//
//  Created by Коля on 15/01/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::ifstream inFile;
    inFile.open("students.txt");
    std::string x;
    std::vector <std::string> students;
    while (inFile >> x)
    {
        students.push_back(x);
    }
    return 0;
}
