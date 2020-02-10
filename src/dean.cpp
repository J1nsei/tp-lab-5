#include "dean.h"
#include "group.h"
#include <vector>
#include <string>
using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

Dean::Dean(string init_name)
{
	name = init_name;
}

Dean::Dean()
{
	
	ifstream file_of_groups("groups.txt");
	system("chcp 1251");
	while (!file_of_groups.eof()) {
		string buf;
		getline(file_of_groups, buf, '\n');
		groups.push_back(new Group(buf));
	}

 
	ifstream file_of_students("students.txt");
	system("chcp 1251");
	while (!file_of_students.eof()) {
		string buf;
		getline(file_of_students, buf, '\n');
		vector<string> data = split(buf, ':');
		for (int i = 0; i < groups.size(); i++) {
			string name_of_group = groups[i]->getName();
			if (name_of_group == data[1]) {
				groups[i]->addStudent(new Student(data[0],data[1]));
				break;
			}
		}
	}
};

void Dean::addGroup(Group* new_group)
{
	groups.push_back(new_group);
}

void Dean::setMarks() {
	for (auto gr : groups)
	{
		gr->setMarks();
	}
}

void Dean::setHeads()
{
	for (auto gr : groups)
	{
		gr->appointHead();
	}
}

void Dean::expelStudents(double mark)
{
	for (auto gr : groups)
	{
		gr->expelStudentsWithBadMarks(mark);
	}
}

void Dean::transferStudents(string student_name, string from, string to)
{
	srand(time(NULL));
	Student* student_to_transfer = new Student();
	for (auto gr : groups)
	{
		if (gr->getName() == from)
		{
			student_to_transfer = gr->findStudent(student_name);
			gr->expelStudent(student_to_transfer->getStudentId());
			break;
		}
	}

	for (auto gr : groups)
	{
		if (gr->getName() == to)
		{
			gr->addStudent(student_to_transfer);
			break;
		}
	}
}

void Dean::getStatistics()
{
	double minAvg = 5.;
	string grName;
	for (auto gr : groups)
	{
		if (gr->countAverageMark() < minAvg)
		{
			minAvg = gr->countAverageMark();
			grName = gr->getName();
		}
		cout << gr->getName() << ' ' << gr->countAverageMark() << endl;
	}
	cout << "The group " << grName << " has the worst average mark:" << minAvg << endl;
}

void Dean::saveData() {
	ofstream fout;
	fout.open("output.txt");
	vector<Student*> students;
	vector<int> marks;
	for (auto gr : groups) {
		students = gr->getStudents();
		fout << "Group " << gr->getName() << endl;
		fout << "Average mark:" << gr->countAverageMark() << endl;
		fout << "Head:" << gr->getHeadName() << endl << endl;
		for (auto student : students)
		{
			fout << student->getStudentName() << endl;
			marks = student->getMarks();
			fout << "Marks:";
			for (int i = 0; i < marks.size(); i++)
				fout << marks[i] << ' ';
			fout << endl << endl;
		}
	}
	fout.close();
}

vector<Group*> Dean::getGroups() 
{
	return groups;
}