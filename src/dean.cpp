//
// Created by Илья on 026 26.01.20.
//
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

#include "student.h"
#include "dean.h"

using std::cout;
using std::cin;
using std::endl;

Deanery::Deanery(){
    groups = vector<Group*>();
    last_id = 0;
}


Deanery::~Deanery(){
    for(auto group : groups){
        for(auto student : group->getStudents()){
            delete student;
        }
        delete group;
    }
}

void Deanery::createGroup(string students_filename, string groups_spec_filename) {
    std::ifstream fin;
    fin.open(groups_spec_filename, std::ifstream::in);
    string title, spec;
    while(getline(fin, title, ':')){
        getline(fin, spec);
        groups.push_back(new Group(title, spec));
    }
    fin.close();

    fin.open (students_filename, std::ifstream::in);
    std::string fio;
    std::string group_name;
    while(getline(fin, fio, ':')){
        getline(fin, group_name, '\n');
        Student* student = new Student(last_id, fio);

        bool if_group_exist = false;
        int group_index = -1;
        for(int i = 0; i < groups.size(); i++){
            if (groups[i]->getTitle() == group_name){
                if_group_exist = true;
                group_index = i;
            }
        }
        if (!if_group_exist){
            groups.push_back(new Group(group_name, ""));
            group_index = groups.size() - 1;
        }
        groups[group_index]->addStudent(student);
        student->addToGroup(groups[group_index]);
        last_id++;
    }
    fin.close();
}


void Deanery::printData() {
    for(Group* group : groups){
        cout << endl << endl;
        cout << group->getTitle() << " " << group->getSpec() << endl;
        if (group->getHead() == nullptr){
            cout << "Head isn't chosen" << endl;
        }
        else{
            cout << "Head: " << group->getHead()->getFio() << endl;
        }
        for(Student* student : group->getStudents()) {
            string f = student->getFio();
            cout << "\t" << student->getFio() << ", id = " << student->getId() << ", average mark = " << student->calcAverageMark() << endl;
            cout << "\t\t" << "marks:";
            for(int mark : student->getMarks()){
                cout << " " << mark;
            }
            cout << endl;
        }
    }
}


void Deanery::addRandomMarks(int n) {
    srand(time(0));
    for(Group* group : groups){
        for(Student* student : group->getStudents()){
            for(int i = 0; i < n; i++){
                student->addMark(rand() % 11);
            }
        }
    }
}


void Deanery::fullStatistics() {
    cout << endl;
    for(Group* group : groups){
        cout << endl << "Group: " << group->getTitle() << ", spec = " << group->getSpec() << ", average mark = " << group->calcAverageMark() << endl;
        vector<Student*>& students = group->getStudents();
        std::sort(students.begin(), students.end(), [](Student* st1, Student* st2){
            return st1->calcAverageMark() > st2->calcAverageMark();
        });
        for(Student* student : students){
            cout << "\t" << student->getFio() << ", id = " << student->getId() << ", average mark = " << student->calcAverageMark() << endl;
        }
        cout << "Total: " << students.size() << " students" << endl;
    }

}


void Deanery::changeGroup(string fio, string gr1_title, string gr2_title){
    Group* gr1 = nullptr;
    Group* gr2 = nullptr;
    for(Group* group : groups){
        if (group->getTitle() == gr1_title){
            gr1 = group;
        }
        if (group->getTitle() == gr2_title){
            gr2 = group;
        }
    }

    if (gr1 != nullptr && gr2 != nullptr){
        Student* student = gr1->findFio(fio);
        if (student != nullptr){
            gr1->excludeStudent(student);
            gr2->addStudent(student);
        }
    }
}


void Deanery::excludeStudents() {
    for(Group* group : groups){
        //vector<Student*>& students = group->getStudents();
        for(auto i = group->getStudents().begin(); i != group->getStudents().end(); i++){
            if ((*i)->calcAverageMark() < 4){
                group->excludeStudent(*i);
                i--;
            }
        }
    }
}


void Deanery::saveData(string students_filename, string groups_filename) {
    std::ofstream fout;
    fout.open(students_filename);
    if (fout.is_open()) {
        bool current_student_first = true;
        for(Group* group : groups){
            for(Student* student : group->getStudents()){
                if (!current_student_first){
                    fout << "\n";
                }
                fout << student->getFio() << ":" << group->getTitle();
                current_student_first = false;
            }

        }
    }
    else{
        cout << "Cannot open file" << endl;
    }

    std::ofstream fout_gr;
    fout_gr.open(groups_filename);
    if (fout_gr.is_open()){
        bool current_group_first = true;
        for(Group* group : groups){
            if (!current_group_first){
                fout_gr << "\n";
            }
            fout_gr << group->getTitle() << ":" << group->getSpec();
            current_group_first = false;
        }
    }
    else{
        cout << "Cannot open file" << endl;
    }
}


void Deanery::chooseHeads() {
    for(Group* group : groups){
        vector<Student*> students = group->getStudents();
        std::sort(students.begin(), students.end(), [](Student* st1, Student* st2){
            return st1->calcAverageMark() > st2->calcAverageMark();
        });
        group->addHead(students[0]);
    }
}