#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Group;
class Deanery;

class Student
{
	friend Group;
	friend Deanery;

public:

	Student(int id, std::string fio);
	void JoinGroup(Group * group);
	void AddMark(int number);
	double AvrMark();

private:

	int id;
	std::string fio;
	Group *group;
	std::vector<int> marks;
};


class Group
{
	friend Deanery;

public:

	Group(std::string title);
	void JoinGroup(Student *student);
	void ChooseLid();
	int Search(int id);  //место по списку в группе начиная с 0-ого
	double AvrMark();
	void Delete(int id);

	//для тестиков 
	std::string GetLider();

private: 

	std::string title;
	std::vector<Student *> students;
	Student *lider;

};

class Deanery
{
public:

	void CreateSt(std::vector<std::string> fio);
	void CreateGr(std::string title1, std::string title2, std::string title3);
	void AddMarks();
	void Statictic(FILE *list); // фамилии с оценками
	void ChangeGr(int id, std::string title);
	void DeleteSt(int id);
	void SaveData(FILE *students); // обновление исходного файла с фамилиями
	void ChooseLid();
	void about(); //тоже самое, что статистика, только с выводом на консоль

	//для тестиков 
	std::string GroupName(int number);

private:

	std::vector<Group> groups;
	std::vector<Student> allstudents;
};
