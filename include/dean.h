//
// Created by Egor on 22.01.2020.
//

#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H

#include <vector>
#include <string>

class Group;

class Dean
{
public:
    Dean(std::string);
    void AddRandomMarksToStudents();
    bool ChangeGroupOfStudent(Group* from, Group* in, int ID);
    void ShowStatistics();
    void CheckForKick();
    void SaveData(std::string);
    void ChangeHeads();
    bool IsGroupExist(std::string);
    void ShowShortStatistics();
    Group* GetGroup(std::string);
private:
    std::vector<Group*> groups;
};

#endif //TASK1_DEAN_H
