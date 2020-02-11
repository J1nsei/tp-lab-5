#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include "Deanery.h"
using namespace std;


bool Deanery::GroupExist(string title) {
    for(auto group: this->groups){
        if(group->GetTitle() == title)
            return true;
    }
    return false;
}


Deanery::Deanery(){
    ifstream stream_from("file.txt");
    string input;
    bool studentFlag = false;
    string currentStudentName;
    while (getline(stream_from, input, '\n')){
        string line;
        stringstream inputStream(input);
        while (getline(inputStream, line, ';')){
            if (!studentFlag){
                currentStudentName = line;
                studentFlag = true;
                continue;
            }
            auto student = new Student(currentStudentName);
            if (!GroupExist(line)){
                auto group = new Group(line);
                group->AddStudent(student);
                this->groups.push_back(group);
            }
            else{
                for (auto group : this->groups)
                    if (group->GetTitle() == line){
                        group->AddStudent(student);
                        break;
                    }
            }
            studentFlag = false;
        }
    }
    stream_from.close();
    this->AddRandomMarks();
    this->ChangeHeads();
}


void Deanery::AddRandomMarks() {
    for(auto group: this->groups)
        for(auto student: group->students){
            student->marks.push_back(rand()%10 + 1);
        }
}


void Deanery::GetStatistics() {
    for(auto group: this->groups){
        cout<<"Group: "<<group->GetTitle()<<endl;
        for(auto student: group->students){
            cout<<student->GetFio()<<"\t"<<student->GetID()<<"\tAverage mark:"<<student->GetAverageMark()<<endl;
        }
        cout<<"______________"<<endl;
    }
}


bool Deanery::ChangeGroup(Group *from, Group *to, int ID) {
    if(from == to)
        return false;
    for(auto student: from->students){
        if(student->GetID() == ID){
            to->AddStudent(student);
            from->DeleteStudent(student);
            return true;
        }
    }
    return false;
}


void Deanery::ExpelStudent() {
    vector <Student*> onDrop;
    for(auto group: this->groups){
        for(auto student: group->students){
            if(student->GetAverageMark() < 4){
                onDrop.push_back(student);
            }
        }
    }
    for(auto current_student: onDrop)
        for(auto group: this->groups)
            if(group->DeleteStudent(current_student)) {
                delete current_student;
                break;
            }
}


void Deanery::SaveData(string path) {
    ofstream out;
    out.open("file.txt");
    out << "";
    out.close();
    out.open(path, ios::app);
    for (auto group : this->groups)
        for (auto student : group->students)
            out << student->GetFio() << ";" << group->GetTitle() << endl;
    out.close();
}


void Deanery::ChangeHeads() {
    for(auto group: this->groups)
        group->AddHead();
}


void Deanery::PrintData() {
    int i = 0;
    for(auto group: this->groups){
        cout<< ++i << " " << group->GetTitle()<<" Number of students: "<<group->students.size()<<" Head: "<< group->GetHead()<<endl;
    }
}

void Deanery::AllGroups() {
    for(auto group: this->groups)
        cout<<group->GetTitle()<<endl;
}