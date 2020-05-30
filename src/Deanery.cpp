#include "Deanery.h"
#include <sstream>

vector<string> split(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

Deanery::Deanery() {}

void Deanery::createGroups(string groups_file) {
	ifstream file(groups_file);
	if (file.is_open()) {
		string buf;
		vector<string> data;
		while (getline(file, buf)) {
			data = split(buf, ':');
			groups.push_back(new Group(data[0], data[1]));
		}
	}
	file.close();
}

void Deanery::createStudents(string students_file) {
	ifstream file(students_file);
	if (file.is_open()) {
		string fio;
		vector<string> data;
		while (getline(file, fio)) {
			data = split(fio, ':');
			Student* student = new Student(data[0], d_id);
			Group* group_name = findGroup(data[1]);
			if (group_name == nullptr)
				addGroup(group_name);
			group_name->addStudent(student);
			d_id++;
		}
	}
	file.close();
}

void Deanery::addGroup(Group* new_group) {
	groups.push_back(new_group);
}

Group* Deanery::findGroup(string group_name) const {
	for (auto gr : groups)
		if (gr->getGroupName() == group_name)
				return gr;
	return nullptr;
}

void Deanery::addMarks(int num = 1) {
	int mark;
	for (auto gr : groups)
		for (auto student : gr->getGroupStudents()) {
			for (int i = 0; i < num; i++) {
				mark = rand() % 5 + 1;
				student->addMark(mark);
			}
		}
}

void Deanery::setHeads() {
	for (auto gr : groups)
		gr->chooseHead();
}

void Deanery::removeStudents(double min_mark = 2.5) {
	int average;
	for (auto gr : groups)
		for (auto student : gr->getGroupStudents()) {
			average = student->averageMark();
			if (average < min_mark)
				gr->removeStudent(student);
		}
}

void Deanery::transferStudent(string fio, string to) {
	Student* student = nullptr;
	for (auto gr : groups) {
		student = gr->findStudent(fio);
		if (student != nullptr) break;
	}
	if (student == nullptr) {
		cout << "There are no students with this FIO" << endl;
		return;
	}
	Group* from_group = student->getGroup();
	Group* to_group = findGroup(to);
	if (to_group == nullptr) return;
	from_group->removeStudent(student);
	to_group->addStudent(student);
}

void Deanery::getStatistics() {
	double avrMark;
	for (auto gr : groups) {
		avrMark = gr->averageGroupMark();
		cout << "Group: " << gr->getGroupName() << ", specialization: " << gr->getGroupSpec() << endl;
		cout << "Number of students: " << gr->getGroupStudents().size() << endl;
		cout << "Head FIO: " << gr->getGroupHead()->getName() << endl;
		cout << "Average mark: " << avrMark << endl;
		Student* best = nullptr;
		Student* worst = nullptr;
		double best_mark = 0, worst_mark = 5;
		for (auto student : gr->getGroupStudents()) {
			if (student->averageMark() >= best_mark) {
				best = student;
				best_mark = student->averageMark();
			}
			else
				if (student->averageMark() <= worst_mark) {
					worst = student;
					worst_mark = student->averageMark();
				}
		}
		cout << "Best student of the group: " << best->getName() << " with average mark " << best_mark << endl;
		cout << "Worst student of the group: " << worst->getName() << " with average mark " << worst_mark << endl << endl;
	}
}

void Deanery::saveData() {
	ofstream fout;
	fout.open("output.txt");
	vector<Student*> students;
	vector<int> marks;
	for (auto gr : groups) {
		students = gr->getGroupStudents();
		fout << "Group: " << gr->getGroupName() << ", specialization: " << gr->getGroupSpec() << endl;
		fout << "Average mark: " << gr->averageGroupMark() << endl;
		fout << "Head: " << gr->getGroupHead()->getName() << endl << endl;
		for (auto student : students) {
			fout << student->getName() << endl;
			marks = student->getMarks();
			fout << "Marks: ";
			for (int i = 0; i < marks.size(); i++)
				fout << marks[i] << ' ';
			fout << endl << endl;
		}
	}
	fout.close();
}

vector<Group*> Deanery::getGroups() {
	return groups;
}
