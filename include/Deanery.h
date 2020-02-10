#ifndef DEANERY_H
#define DEANERY_H

#include "Group.h"
#include <fstream>

class Deanery
{
private:
    std::vector<Group*> groups;
public:
    Deanery();
    void creationOfGroups(std::string fileName);
    std::vector<Group*> getGroups() const;
    void creationOfStudents(std::string fileName);
    void addRandomMarks();
    std::vector<double> getPerformance();
    void transfer(Student* st, Group* gr1, Group* gr2);
    void excludeBadStudents();
    void save(std::string filename);
    ~Deanery();
};

#endif // DEANERY_H