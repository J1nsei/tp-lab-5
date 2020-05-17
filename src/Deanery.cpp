#include "Deanery.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MINAVG 3.5
using namespace std;

Deanery::Deanery(){};

vector<string> parseString(string s, char delimiter){
    size_t pos = 0;
    std::string parsedStr;
    vector<string> res = {};
    while ((pos = s.find(delimiter)) != std::string::npos) {
        parsedStr = s.substr(0, pos);
        res.push_back(parsedStr);
        s.erase(0, pos + 1);
    }
    res.push_back(s);
    return res;
}

void Deanery::setDataGroups(){
    string s;
    ifstream fileGroups(this->filenameGroups);
    while(getline(fileGroups, s)){
        vector<string>data = parseString(s, ';');
        Group* group = new Group(data[0], data[1]);
        groups.push_back(group);
    }
    fileGroups.close();
}

void Deanery::setDataStudents(){
    string s;
    ifstream fileStudents(this->filenameStudents);
    while(getline(fileStudents, s)){
        vector<string>data = parseString(s, ';');
        Student* student = new Student(stoi(data[0]), data[1]);
        for (Group* group: this->getGroups()){
            if (group->getTitle() == data[2]){
                group->addStudent(student);
                student->addToGroup(group);
            }
        }
    }
    fileStudents.close();
}

void Deanery::addRandomMarks(){
    srand(static_cast<unsigned int>(time(nullptr)));
    for (Group* group: this->getGroups()) {
        for (Student* student: group->getStudents()){
            for (int i = 0; i < 3; i++) {
                int randMark = rand() % 10 + 1;
                student->addMark(randMark);
            }
        }
    }
}

void Deanery::getStatistics(){
    for (Group* group: this->getGroups()) {
        cout << "===========================================" << endl << endl;
        cout << " >>> Статистика по группе " << group->getTitle() << " " << group->getSpec() << endl;
        cout << "Средняя оценка в группе = " << group->getAverageMark() << endl << endl;
        cout << "-------------------------------------------" << endl << endl;
        cout << "Средние оценки студентов:" << endl << endl;
        for (Student* student: group->getStudents()){
            cout << "ID: " << student->getID() << " " << student->getFIO() << " = " << student->getAverageMark() << endl;
        }
        cout << "===========================================" << endl << endl;
    }
}

void Deanery::moveStudent(string fio, string groupTitle) {
    bool flag = false;
    Group* toGroup = nullptr; Student* student = nullptr;
    for (Group* group: this->getGroups()) {
        if (group->getTitle() == groupTitle) {
            toGroup = group;
            for (Group* group: this->getGroups()) {
                student = group->findStudentByName(fio);
                if (student != nullptr) {
                    student->addToGroup(toGroup);
                    toGroup->addStudent(student);
                    group->deleteStudent(student->getID());
                    flag = true;
                    break;
                }
            }
            break;
        }
    }
}

void Deanery::dropStudents() {
    for (Group* group: this->getGroups()) {
        for (Student* student: group->getStudents()){
            if (student->getAverageMark() < MINAVG) {
                while (group->getHead()->getID() == student->getID()){
                    Student* head = group->getStudents()[rand() % group->getStudents().size()];
                    group->changeHead(head);
                }
                group->deleteStudent(student->getID());
            }
        }
    }
}

void Deanery::electHead() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (Group* group: this->getGroups()) {
        Student* head = group->getStudents()[rand() % group->getStudents().size()];
        group->changeHead(head);
    }
}

void Deanery::showData() {
    for (Group* group: this->getGroups()) {
        cout << "Группа: " << group->getTitle() << " | Специальность: " << group->getSpec() << endl;
        cout << "Староста: " << group->getHead()->getFIO() << endl << endl;
        for (Student* student: group->getStudents()) {
            cout << "ID: " << student->getID() << " | Имя: " << student->getFIO() << " | Оценки: ";
            for  (int mark: student->getMarks()) {
                cout << mark << " ";
            }
            cout << "| Средняя оценка: " << student->getAverageMark() << endl;
        }
        cout << endl;
    }
}

void Deanery::saveData() {
    std::ofstream out(filenameStudents);
    for (Group *group: this->getGroups()) {
        for (Student *student: group->getStudents()) {
            out << student->getID() << ";" << student->getFIO() << ";" << group->getTitle() <<"\n";
        }
    }
    out.close();
}

vector<Group*> Deanery::getGroups() {
    return this->groups;
}
