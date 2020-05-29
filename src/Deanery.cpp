//
//  Deanery.cpp
//  Shtanyuk5
//
//  Created by Коля on 26/02/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#include "Deanery.hpp"

void addStudentsFromFile(std::string file)
{
    std::ifstream students_file(file);
    if (!students_file.is_open())
    {
        std::cout << "Error opening students file" << std::endl;
        return;
    }
    
}

void addGroupsFromFile (std::string file)
{
    std::ifstream group_file(file);
    if (!students_file.is_open())
    {
        std::cout << "Error opening groups file" << std::endl;
        return;
    }
    std::string str;
    while (std::getline(group_file, str))
    {
        groups.insert(new Group(str));
    }
}
