//
// Created by Anton Korkunov on 16/01/2020.
//

#ifndef LAB5_DEANERY_H
#define LAB5_DEANERY_H
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "Group.h"

using namespace std;

class Deanery{
private:
  vector<Group*> groups;
public:
    Deanery();
  void createStudents(vector<string> StudNAME, vector <Student> *StudentList);
  void createGroups(vector<string> Groups, vector <Group> *GroupList);
  void makeMarks();
  int getStat();
  void StudSwap(Student* candidat, Group* Gto);
  void DelStud(double aver);
  void SaveData();
  void HeadChoice();
  void OutPut();
  void fillupGRs(vector <Student> *StudentList);
};
#endif //LAB5_DEANERY_H
