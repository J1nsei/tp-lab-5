#ifndef DEAN_H
#define DEAN_H

#include "Group.h"
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
class Dean {
	friend Group;
public:
	Dean() {};
	Dean(Group);
	Dean(const string&);
	void check_students();
	void check_delete_students();
	void add_random_marks(const string, int);
	vector<string>split(const string& , char );
	void create_students();
	void transfer_student(const string,const string,const string);
	Group* find_group(const string&);
	void set_marks(const string, int, const vector<int>);
	void choose_head(const string);
	void perform_file(const string&);
	void data_output(const string);
	void add_group(const Group&);
	vector<Group> get_groups() const;
private:
	vector<Group>groups;
};

#endif