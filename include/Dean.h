#pragma once
#ifndef DEAN_H
#define DEAN_H
#include <sstream>
#include "group.h"

class Dean {
private:
	vector<Group> groups;
public:
	Dean();
	void setMarks();
	Group* findGroup(const string);
	void setHeads();
	void allocation(); 
	void transfer(const string, const string); 
	void scholarship();
	void statistics();
	void savingData();
	unsigned int getStudents();
	unsigned int getGroups();
};
#endif 