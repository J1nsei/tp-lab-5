#pragma once
#ifndef DEAN_H
#define DEAN_H
#include <sstream>
#include "group.h"

class Dean {
	private:
		vector<Group*> groups;
		string name;
	public:
		Dean();
		Dean(string);
		void addGroup(Group*);
		void setMarks();
		void setHeads();
		void expelStudents(double);
		void transferStudents(string,string,string);
		void getStatistics();
		void saveData();
		vector<Group*> getGroups();
};
#endif