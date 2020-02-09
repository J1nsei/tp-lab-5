#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include<vector>
#include <sstream>
#include "Student.h"
#include "Group.h"
#include "Dean.h"

/*
std::string randomGroups(std::string fileName) {
	std::string groups[4] = { "18PI-1", "18PI-2", "18PMI-1", "18PMI-2" };
	std::string s;
	std::ifstream file(fileName);
	std::string data = "";
	srand(time(NULL));
	while (!file.eof()) {
		getline(file, s, '\n');
		data += s + ";" + groups[rand() % 4] + '\n';
	}
	file.close();
	return data;
}


void writeToFile(std::string fileName, std::string data) {
	std::ofstream file(fileName);
	if (file.is_open()) {
		file << data;
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}	
}


void writeMapToFile(std::map<std::string, std::string> data, std::string fileName) {
	std::ofstream file(fileName);
	if (file.is_open()) {
		std::map <std::string, std::string> ::iterator it = data.begin();
		for (; it != data.end(); it++) {
			file << it->first << ";" << it->second << '\n';
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
}


std::vector<std::string> readFile(std::string fileName) {
	std::ifstream file(fileName);
	std::string s;
	std::vector<std::string> data;
	system("chcp 1251");
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, s, '\n');
			if (s != "") {
				data.push_back(s);
			}
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
	return data;
}


std::vector<std::vector<std::string>> split(std::vector<std::string> data, char delimeter) {
	std::string temp;
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> item;
	for (auto element : data) {
		std::stringstream ss(element);
		while (getline(ss, temp, delimeter)) {
			item.push_back(temp);
		}
		result.push_back(item);
		item.clear();
	}	
	return result;
}

*/
/*std::map<std::string, std::string> split(std::vector<std::string> data, char delimeter) {
	std::map<std::string, std::string> students;
	std::string temp;
	std::vector<std::string> item;
	for (auto element : data) {
		std::stringstream ss(element);
		while (getline(ss, temp, delimeter)) {
			item.push_back(temp);
		}
		students[item.at(0)] = item.at(1);
		item.clear();
	}
	return students;
}
*/
/*
void printVector(std::vector<std::vector<std::string>> &vec) {
	for (auto& item : vec) {
		for (auto& el : item) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
}


std::map<std::string, std::string> createMap(std::vector<std::vector<std::string>> data) {
	std::map<std::string, std::string> students;
	for (auto& item : data) {
		students[item.at(0)] = item.at(1);
	}
	return students;
}


void printMap(std::map<std::string, std::string> data) {
	std::map <std::string, std::string> ::iterator it = data.begin();
	for (int i = 1; it != data.end(); it++, i++) { 
		std::cout << "№" << i << " " << it->first << " " << it->second << std::endl;
	}
}

std::vector<std::string> split_new(std::string str, char delimeter) {
	std::vector<std::string> result;
	std::string newStr= "";
	for (char i : str) {
		if (i == delimeter) {			
			result.push_back(newStr);
			newStr = "";		
		}
		else {
			newStr += i;
		}
	}
	result.push_back(newStr);
	return result;
}


}
*/
int main() {
	Dean* dean = new Dean("students.csv");
	dean->createGroups();
	Group* group = dean->findGroupByName("18PI-2");
	Group* group2 = dean->findGroupByName("18PMI-1");
	std::cout << group << std::endl;
	dean->createStudents();
	if (group != 0) {
		std::cout << group->getName() << std::endl;
		Student* Igor = group->findStudentById(35);
		Student* Sasha = group->findStudentByName("Конак Альбина Эрнестовна");
		Student* Miroslava = group->findStudentByName("Хейчеева Василиса Сидоровна");

		if (Igor != 0 && Sasha != 0) {
			for (int i = 0; i < 5; i++) {
				Igor->addMark(i);
				Sasha->addMark(i + 1);
			}
			std::cout << "Igor " << Igor << std::endl;
			std::cout << "Sasha " << Sasha << std::endl;
			std::cout << "Miroslava " << Miroslava << std::endl;
			if (Igor != 0) {
				//information about student
				std::cout << "FIO " << Igor->getFIO() << std::endl;
				std::cout << "Group " << Igor->getGroup()->getName() << std::endl;
				std::cout << "ID " << Igor->getID() << std::endl;
				//student and group statistics
				std::cout << "Average mark Igor " << Igor->averageMark() << std::endl;
				std::cout << "Average mark Sasha " << Sasha->averageMark() << std::endl;
				std::cout << "Group statistics " << group->averageMark() << std::endl;
				std::cout << dean->getGroupStatistics(group) << std::endl;
			}
			group->setHead(Miroslava);
			std::cout << "Head " << group->getHead() << std::endl;
			//delete student
			dean->expelStudent(Miroslava);			
			std::cout <<"Head "<< group->getHead() << std::endl;
			std::cout << "Miroslava " << Miroslava << std::endl;

			//transfer student
			std::cout << "Sasha group before transfer " << Sasha->getGroup()->getName() << std::endl;
			dean->studentTransfer(Sasha, group2);
			std::cout << "Sasha group after transfer " << Sasha->getGroup()->getName() << std::endl;

			//add student		
			dean->addNewStudent("Сидорова Мария Ивановна", group2);
			Student* newStudent = group2->findStudentByName("Сидорова Мария Ивановна");
			std::cout << "Group new sudent " << newStudent->getGroup()->getName() << std::endl;
			std::cout << "Name new student " << newStudent->getFIO() << std::endl;
			std::cout << "ID new student " << newStudent->getID() << std::endl;
			dean->updateData();
			dean->outputData();
		}
	}
	//dean->getGroupStatistics(group);	
	//dean->outputData();
}
