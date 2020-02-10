#include "Deanery.h" 
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

#define LOWEST_MARK 4
Deanery::Deanery(string file_students, string file_groups) {
	string FileStud = file_students;
	string FileGrp = file_groups;
}

void Deanery::MakeStudents(){

	ifstream file("students.txt");
	if (file.is_open()) {
		string NameOfStud;
		int _id = 1;
		while (getline(file, NameOfStud)) {
			VseStud.push_back(new Student(_id, NameOfStud));
			_id++;
		}
	}
	else {
		cout << "Not open!";
	}
	file.close();
}
void Deanery::MakeGroups() {
	ifstream file("groups.txt");
	if (file.is_open()) {
		string NameOfGrp;
		while (getline(file, NameOfGrp)) {
			groups.push_back(new Group(NameOfGrp));
			}
	}
	else {
		cout << "Not open!";
	}
	file.close();
	for (Student* student : VseStud)
	{
		groups[rand() % groups.size()]->AddStudent(student);
	}
	
}
void Deanery::AddMarks() {
	for (int i = 0; i < VseStud.size(); i++) {
		VseStud[i]->AddMark();
		VseStud[i]->AddMark();
		VseStud[i]->AddMark();
		VseStud[i]->AddMark();
	}
}
void Deanery::HeadInit() {
	for (int i = 0; i < groups.size(); i++) {
		groups[i]->ChosHead();
	}
}
void Deanery::StudentDelete() {
	for (int i = 0; i < VseStud.size(); i++) {
		if (VseStud[i]->MedMark() < LOWEST_MARK) {
			string TitleOfGroup = VseStud[i]->group;
			for (int j = 0; j < groups.size(); j++) {
				if (groups[j]->title == TitleOfGroup) {
					groups[j]->DeleteStud(VseStud[i]->id);
					VseStud.erase(VseStud.begin() + i);
				}
			}
		}
	}
}
void Deanery::ChangeGroup(Student* stud, string title_target_group) {
	for (int i = 0; i < groups.size(); i++) {
		if (groups[i]->title == title_target_group) {
			string LastGroup = stud->group;
			for (int j = 0; j < groups.size(); j++) {
				if (groups[j]->title == LastGroup) {
					groups[j]->DeleteStud(stud->id);
				}

			}
			stud->AddInGroup(groups[i]->title);
			groups[i]->AddStudent(stud);
		}
	}
	
}
void Deanery::Statistic(ostream* stream) {
	for (int i = 0; i < groups.size(); i++) {

		*stream << "The name of the group:" << groups[i]->title << endl;
		*stream << "The number of students:" << groups[i]->GetSize() << endl;
		*stream << "The head of the group:" << groups[i]->head->fio << endl;
		*stream << "The midle mark of the group:" << groups[i]->MediumMarkG() << endl;
		int TheBestStudent = -1;
		int TheBestMark =0;
		for (int j = 0; j < groups[i]->students.size(); j++) {
			if (groups[i]->students[j]->MedMark() > TheBestMark) {
				TheBestStudent = groups[i]->students[j]->id;
				TheBestMark = groups[i]->students[j]->MedMark();
			}
		}
		*stream << "The best student is:" << groups[i]->SearshStud(TheBestStudent)->fio<<endl;
		int TheWorstStudent = -1;
		int TheWorstMark = 6;
		for (int j = 0; j < groups[i]->students.size(); j++) {
			if (groups[i]->students[j]->MedMark() < TheWorstMark) {
				TheWorstStudent = groups[i]->students[j]->id;
				TheWorstMark = groups[i]->students[j]->MedMark();
			}
		}
		*stream << "The worst student is:" << groups[i]->SearshStud(TheWorstStudent)->fio<<endl;

		for (int j = 0; j < groups[i]->students.size(); j++)
		{
			*stream << groups[i]->students[j]->fio << endl;
			*stream<<"Medium ball:"<<groups[i]->students[j]->MedMark() << "   ";
			*stream << "Marks:";
			for (int h = 0; h < groups[i]->students[j]->marks.size(); h++)
			{
				*stream << groups[i]->students[j]->marks[h] << " ";
			}
			*stream << "" << endl;
		}
	
	}
		 
	}
	
	
	
void Deanery::New() {
	ofstream file_out("output.txt", ios_base::trunc);
	Statistic(new ostream(file_out.rdbuf()));
}
void Deanery::PrintInf() {
	for (int i = 0; i < groups.size(); i++) {

		cout << "The name of the group:" << groups[i]->title << endl;
		cout << "The number of students:" << groups[i]->GetSize() << endl;
		cout << "The head of the group:" << groups[i]->head->fio << endl;
		cout << "The midle mark of the group:" << groups[i]->MediumMarkG() << endl;
		int TheBestStudent = -1;
		int TheBestMark = 0;
		for (int j = 0; j < groups[i]->students.size(); j++) {
			if (groups[i]->students[j]->MedMark() > TheBestMark) {
				TheBestStudent = groups[i]->students[j]->id;
				TheBestMark = groups[i]->students[j]->MedMark();
			}
		}
		cout << "The best student is:" << groups[i]->SearshStud(TheBestStudent)->fio << endl;
		int TheWorstStudent = -1;
		int TheWorstMark = 6;
		for (int j = 0; j < groups[i]->students.size(); j++) {
			if (groups[i]->students[j]->MedMark() < TheWorstMark) {
				TheWorstStudent = groups[i]->students[j]->id;
				TheWorstMark = groups[i]->students[j]->MedMark();
			}
		}
		cout << "The worst student is:" << groups[i]->SearshStud(TheWorstStudent)->fio << endl;
	}
}