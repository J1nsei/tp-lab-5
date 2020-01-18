#ifndef DEANERY_H
#define DEANERY_H

#include "Group.h"

class Deanery
{
private:
    std::vector<Group*> groups;
public:
    Deanery(/* args */);
    ~Deanery();
};

#endif // DEANERY_H