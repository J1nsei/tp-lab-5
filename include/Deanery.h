#ifndef DEANERY_H
#define DEANERY_H

#include "Group.h"
#include <fstream>

class Deanery
{
private:
    std::vector<Group*> groups;
public:
    Deanery(/* args */);
    void creationOfGroups(std::string fileName);
    ~Deanery();
};

#endif // DEANERY_H