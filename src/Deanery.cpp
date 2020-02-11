//
// Created by fiskirton on 10.02.2020.
//

#include "../include/Deanery.h"
#include "Student.h"
#include "Group.h"

#include <iostream>
#include <fstream>
#include "helper.h"

Deanery::Deanery(const string& students_file_path, const string& groups_file_path) {

    this->students_file_path = students_file_path;
    this->groups_file_path = groups_file_path;

    init();
    chooseHeadmen();

}

Deanery::~Deanery() {

    for (auto group: groups){
        delete group;
    }

    groups.clear();

}

void Deanery::init() {

    string line;
    vector<string> data;

    ifstream groups_in(groups_file_path);

    if (groups_in.is_open()){
        while (getline(groups_in, line)) {

            data = split(line, ',');
            auto new_group = new Group(stoi(data[0]), data[1], data[2]);
            groups.push_back(new_group);

        }

        groups_in.close();

    } else return;

    ifstream students_in(students_file_path);

    if (students_in.is_open()){


        while (getline(students_in, line)) {

            data = split(line, ',');
            auto student = new Student(stoi(data[0]), data[2]);
            student->setGroup(groups[stoi(data[1])]);
            auto & group = student->getGroup();
            group.addStudent(student);

        }

        students_in.close();

    } else return;

}

void Deanery::chooseHeadmen() {

    for (auto group: groups) {
        group->setHead(group->getStudents()[0]);
    }

}

void Deanery::refreshData() {

    string line;

    ofstream students_out(students_file_path);

    if (students_out.is_open()) {
        for (auto group: groups) {
            for (auto student: group->getStudents()) {
                students_out << to_string(student->getId()) << ',' << to_string(group->getGroupId()) << ',' << student->getFio() << endl;
            }
        }
    }

}

void Deanery::addRandomMarks() {

    for (auto group: groups) {
        for (auto student: group->getStudents()){
            student->addMark(getRandom(1, 10));
        }

        group->countGroupMean();

    }

}

string Deanery::getStatistics() {

    string students_statistics;
    string groups_statistics;
    string line;

    for (auto group: groups) {
        for (auto student: group->getStudents()){
            line = group->getTitle() + " " + student->getFio() + " " + to_string(student->getMeanMark()) + "\n";
            students_statistics += line;
        }

        line = group->getTitle() + " " + to_string(group->getGroupMeanMark()) + "\n";
        groups_statistics += line;

    }

    string statistics = students_statistics + "\n" + groups_statistics;

    return statistics;

}

void Deanery::transferStudent(int id, const string &destination) {

    Student *student = nullptr;
    Group *dest_group = nullptr;

    for (auto group: groups) {

        if ((student = group->findStudent(id)) != nullptr) {
            break;
        }

    }

    for (auto group: groups){

        if (group->getTitle() == destination) {
            dest_group = group;
        }

    }

    if (student != nullptr && dest_group != nullptr) {

        auto & group = student->getGroup();

        if (&group != dest_group) {

            group.excludeStudent(student);
            dest_group->addStudent(student);
            student->setGroup(dest_group);
            refreshData();

        }

    }

}

void Deanery::excludeStudent(int id) {

    Student * student = nullptr;

    for (auto group: groups) {

        if((student = group->findStudent(id)) != nullptr){
            break;
        }

    }

    if (student != nullptr){

        auto & group = student->getGroup();
        group.excludeStudent(student);
        delete student;
        refreshData();

    }

}

const vector<Group *> & Deanery::getGroups() const {
    return groups;
}
