#pragma once
#include<string>
#include<vector>

class Group;

class Student
{
private:
	unsigned int id;
	std::string fio;
	Group* group;
	std::vector<int> marks;	
	//void setGroup(Group* group);
public:
	Student();
	Student(unsigned int id, std::string fio);

	void setID(unsigned int id);
	unsigned int getID();

	void setFIO(std::string fio);	
	std::string getFIO();

	void setGroup(Group* group);
	Group* getGroup();

	void addMark(int mark);
	double averageMark();	
	~Student();
};

