#pragma once

#include <iostream>
#include <string.h>
#include <vector>

#include "student.h"

class Group
{
public:
	Group();
	~Group();

private:
	string title;
	string spec;
	vector<Student&> students;
	Student& head;
};

Group::Group()
{
}

Group::~Group()
{
}