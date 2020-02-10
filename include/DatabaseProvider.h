#ifndef _DATABASEPROVIDER_H_
#define _DATABASEPROVIDER_H_

#include <iostream>
#include <vector>
#include "Group.h"
#include "Student.h"

class DatabaseProvider
{
private:
    std::string m_studentRepositoryFileName;
    std::string m_groupRepositoryFileName;
    std::vector<Student *> m_students;
    std::vector<Group *> m_groups;

public:
    DatabaseProvider(std::string studentRepositoryFileName, std::string groupRepositoryFileName);

    std::vector<Student *> *GetStudents() { return &m_students; }
    std::vector<Group *> *GetGroups() { return &m_groups; }

    void LoadStudents(std::istream &streamReader);
    void LoadStudents();
    void LoadGroups(std::istream &streamReader);
    void LoadGroups();
    void SaveStudents(std::ostream &streamWriter);
    void SaveStudents();
    void SaveGroups(std::ostream &streamWriter);
    void SaveGroups();
};

#endif // _DATABASEPROVIDER_H_
