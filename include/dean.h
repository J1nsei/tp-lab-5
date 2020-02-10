#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "group.h"

using namespace std;

#ifndef DEAN_H
#define DEAN_H

class Group;
class Student;

class Dean
{
private:
	vector <Group*> groups;
	unsigned int dean_id;
public:
	Dean();
	void addGroups(string names_input, string groups_input);
	void set_random_marks(unsigned int number);
	void getStatistics() const;
	void changeGroup(string name, string oldGroup, string newGroup);
	void expelStudents();
	void rewriteData(string students, string groups) const;
	void chooseHeads();
};


#endif