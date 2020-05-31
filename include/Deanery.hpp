//
//  Deanery.hpp
//  Shtanyuk5
//
//  Created by Коля on 26/02/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#ifndef Deanery_hpp
#define Deanery_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Group.hpp"

class Deanery {

private:
    std::vector<Group*> groups;
public:
    Deanery(std::string, std::string);
    void addStudentsFromFile(std::string);
    void addGroupsFromFile(std::string);
    void randomMarks();
    void getStats();
    void studentTransfer();
    void ot4islos(id_t);
    void saveState();
    void elections();
    void printData();
};




#endif /* Deanery_hpp */
