#include"Deanery.h"
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>

vector<Group> Deanery::getGroups(){
	return groups;
}

void Deanery::addGroup(Group group) {
	groups.push_back(group);
}

void Deanery::GenerateMarks(const string& groupName) {
	Group* bufGroup = findGroup(groupName);
	for (auto& it : bufGroup->getStudents()) {
		it.addMark(rand() % 10);
	}
}

Group* Deanery::findGroup(const string& groupTitle)
{
	for (int i = 0; i < groups.size(); i++)
	{
		if (groups[i].getTitle() == groupTitle)
		{
			return &groups[i];
		}
	}
	return nullptr;
}

void Deanery::MoveStudent(const string& groupTitle1, const string& groupTitle2, string name) {
	Group* group1 = findGroup(groupTitle1);
	Group* group2 = findGroup(groupTitle2);
	student *stud = group1->findStudent(name);
	if (stud) {
		group2->addStudent(*stud);
		group1->cickStudent(*stud);
		stud->changeGroup(group2);
	}
	else {
		std::cout << "Error" << endl;
	}
}

void Deanery::CickStudents() {
	for (int i = 0; i < groups.size(); i++) {
		for (int j = 0; j < groups[i].getStudents().size(); i++) {
			if (groups[i].getStudents()[j].getAverage() < 4) {
				groups[i].cickStudent((groups[i].getStudents()[j]));
				groups[i].getStudents()[j].changeGroup(nullptr);
			}
		}
	}
	std::cout << "Failure students has been cicked" << endl;
}

void Deanery::ChooseHead() {
	for (int i = 0; i < groups.size(); i++) {
		int size = groups[i].getStudents().size();
		int newHeadNumb = rand() % size;
		student* newHead = &groups[i].getStudents()[newHeadNumb];
		groups[i].newHead(newHead);
	}
}

int Deanery::GetStatsGroup(const string& groupTitle) {
	Group *group = findGroup(groupTitle);
	return group->getAverage();
}

int Deanery::GetStatsStudent(int id) {
	student *stud = nullptr;
	for (int i = 0; i < groups.size(); i++){
		if (groups[i].findStudent(id)){
			for (int j = 0; j < groups[i].getStudents().size(); j++){
				if ((groups[i].getStudents()[i].getId()) == id){
					return groups[i].getStudents()[i].getAverage();
				}
			}
		}
	}
}

void Deanery::CreateStudents(const string& name){
	string buf;
	string spec;
	int id = 0;
	ifstream fi(name);
	if (fi.is_open()){
		while (!fi.eof()){
			id++;
			getline(fi, buf, ':');
			student student(buf, id);
			getline(fi, buf, '\n');
			Group *group = findGroup(buf);
			if (group){
				student.changeGroup(group);
				group->addStudent(student);
			}
			else{
				for (int i = 2; i < buf.size(); i++) {
					if ((buf[i] >= 'A') && (buf[i] <= 'Z')) {
						spec += buf[i];
					}
				}
				Group newGroup(buf, spec);
				addGroup(newGroup);
				student.changeGroup(&groups[groups.size() - 1]);
				groups[groups.size() - 1].addStudent(student);				
			}
		}
	}
	else
	{
		std::cout << "Error" << endl;
	}
	fi.close();
}

void Deanery::Print(){
	for (auto& group: groups) {
		std::cout << group.getTitle() << " : " << endl;
		for (auto& student : group.getStudents()) {
			std::cout << student.getId() << ":" << student.getFio() << endl;
		}
	}
}

void Deanery::Save(const string name) {
	ofstream out(name);
	if (out.is_open())
	{
		for (int i = 0; i < groups.size(); i++)
		{
			for (int j = 0; j < groups[i].getStudents().size(); j++)
			{
				out << groups[i].getStudents()[j].getId() << ":" << groups[i].getStudents()[j].getFio() << ":" << groups[i].getStudents()[j].getGroup() << endl;
			}
		}
	}
	else
	{
		std::cout << "File is undefined";
	}
	out.close();
}
