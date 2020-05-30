//
// Created by aklen on 01.02.2020.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <Deanery.h>
using namespace std;


bool Deanery::isGroupExist(string title) {
    for(auto group: this->groups){
        if(group->getTitle() == title)
            return true;
    }
    return false;
}


Deanery::Deanery(){
    ifstream stream_from("../src/students.txt");
    string input;
    bool studentFlag = false;
    string currentStudentName;
    while (getline(stream_from, input, '\n')){
        string line;
        stringstream inputStream(input);
        while (getline(inputStream, line, ':')){
            if (!studentFlag){
                currentStudentName = line;
                studentFlag = true;
                continue;
            }
            auto student = new Student(currentStudentName);
            if (!isGroupExist(line)){
                auto group = new Group(line);
                group->addStudent(student);
                this->groups.push_back(group);
            }
            else{
                for (auto group : this->groups)
                    if (group->getTitle() == line){
                        group->addStudent(student);
                        break;
                    }
            }
            studentFlag = false;
        }
    }
    stream_from.close();
    this->addRandomMarksToStudents();
    this->changeHeads();
}


void Deanery::addRandomMarksToStudents() {
    for(auto group: this->groups)
        for(auto student: group->students){
            student->marks.push_back(rand()%10 + 1);
        }
}


void Deanery::getStatistics() {
    cout<<"Statistics:\n";
    for(auto group: this->groups){
        for(auto student: group->students){
            cout<<"ID: "<<student->getID()<<endl;
            cout<<"FIO: "<<student->getFio()<<endl;
            cout<<"Average mark: "<<student->getAverageMark()<<endl;
            cout<<"Group: "<<group->getTitle()<<endl;
        }
        cout<<"---------------------------"<<endl;
    }
}


bool Deanery::removeStudent(Group *from, Group *to, int ID) {
    if(from == to)
        return false;
    for(auto student: from->students){
        if(student->getID() == ID){
            to->addStudent(student);
            from->deleteStudent(student);
            return true;
        }
    }
    return false;
}


void Deanery::checkForKick() {
    vector <Student*> onDrop;
    for(auto group: this->groups){
        for(auto student: group->students){
            if(student->getAverageMark() < 4){
                onDrop.push_back(student);
            }
        }
    }
    for(auto current_student: onDrop)
        for(auto group: this->groups)
            if(group->deleteStudent(current_student)) {
                delete current_student;
                break;
            }
}


void Deanery::rewriteDataFile(string path) {
    ofstream out;
    out.open("../src/students.txt");
    out << "";
    out.close();
    out.open(path, ios::app);
    for (auto group : this->groups)
        for (auto student : group->students)
            out << student->getFio() << ":" << group->getTitle() << endl;
    out.close();
}


void Deanery::changeHeads() {
    for(auto group: this->groups)
        group->newHead();
}


void Deanery::consoleOutPut() {
    cout<<"Some statistic:"<<endl;
    int index = 1;
    for(auto group: this->groups){
        cout<< index++ << " : " << group->getTitle()<<endl;
        cout<< "Amount of students in group: "<<group->students.size()<<endl;
        cout<< "Head of group: "<< group->getHead()<<endl;
    }
}

void Deanery::listOfGroups() {
    for(auto group: this->groups)
        cout<<group->getTitle()<<endl;
    cout<<"-----------\n";
}