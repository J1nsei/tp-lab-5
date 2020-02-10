#include "Group.h"

Group::Group()
{
    //ctor
}

Student* Group::findStudent(unsigned int id){
    for(vector<Student*>::iterator itr = this->students.begin(); itr != this->students.end(); ++itr){
        if((*itr)->getId() == id){
            return (*itr);
        }
    }
    return nullptr;
}

Student* Group::findStudent(std::string name){
    for(vector<Student*>::iterator itr = this->students.begin(); itr != this->students.end(); ++itr){
        if((*itr)->getName() == name){
            return *itr;
        }
    }
    return nullptr;
}

void Group::addStudent(Student* newStudent){
    newStudent->setGroup(this);
    this->students.push_back(newStudent);
    if(this->head == nullptr){
        this->assignHead();
    }
}

void Group::printStList(){
    cout << this->title<< ":" << endl;
    for(auto i: this->students){
        if(i == this->head){
            cout << "Head: ";
        }
        cout << i->getName()<<"<>" <<i->getMidMark() << " id:" << i->getId() << endl;
    }
}

void Group::assignHead(){
    if(this->students.size() == 1){
        this->head = this->students.back();
        return;
    }
    Student* bestMarkSt;
    int bestMark = 0;
    for(auto i: this->students){
        if(i->getMidMark() > bestMark){
            bestMarkSt = i;
            bestMark = i->getMidMark();
        }
    }
    this->head = bestMarkSt;
}

int Group::getMidMark(){
    int sum = 0;
    for(auto i: this->students){
        sum += i->getMidMark();
    }
    return sum/this->students.size();
}

void Group::deleteStudent(Student* st){
    vector<Student*>::iterator it = this->students.begin();
    while(*it != st){
        ++it;
    }
    if(*it == st){
        this->students.erase(it);
    }
    if(st == this->head){
        this->assignHead();
    }
}

Group::~Group()
{
    //dtor
}
