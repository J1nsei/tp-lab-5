#include "Deanery.h"
#include "Group.h"
#include "Student.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

Deanery::Deanery() {
    Group* g = new Group("Unknown Group","Unknown Spec");
    groups = vector<Group*>();
    groups.push_back(g);
}

void Deanery::addGroup(Group* g) {
    groups.push_back(g);
}

void Deanery::importFile(string name, string groupName, string groupSpec) {
    int id = 0;
    Group* g = nullptr;
    string fio;
    ifstream myfile(name);

    if(groupName!="" && groupSpec!=""){
        g = new Group(groupName, groupSpec);
        groups.push_back(g);
    }

    if (myfile.is_open())
    {
        while (! myfile.eof() ) {
            string line;
            getline(myfile, line);
            string delimiter = " ";
            int pos = 0, pos1 = 0;
            while ((pos = line.find(' ') != std::string::npos)) {
                string word = line.substr(0, pos);
                line.erase(0, 1);
                if (word == " ")
                    continue;
                //cout<<line<<endl;
                if(id == 0) {
                    id = stringToInt(word);
                }
                else {
                    fio += word;
                }
            }
            fio += line;
            cout<<id<<endl;
            cout<<fio<<endl;

            Student* student = new Student(id, fio);
            if(g!= nullptr){
                g->addStudent(student);
                student->setGroup(g);
            }
            else{
                groups[0]->addStudent(student);
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Deanery::addRandomMarks() {
    srand(static_cast<unsigned int>(time(0)));
    for(auto i:groups){
        for(auto j:i->getStudents()) {
            for(int i=0;i<20;i++) {
                j->addMark(1 + rand() % 5);
            }
        }
    }
}

void Deanery::getStatistic() {
    for(auto i:groups) {
        std::cout << i->averageMark()<<"   ";
    }
    for(auto i:groups) {
        for (auto j:i->getStudents()) {
            std::cout<<j->averageMark()<<"   ";
        }
        cout<<endl;
    }
}

void Deanery::transfer(int id, string gTitle1, string gTitle2) {
    Group *g1 = nullptr, *g2 = nullptr;
    for(auto i:groups) {
        if(i->getTitle() == gTitle1) {
            g1 = i;
        }
        if(i->getTitle() == gTitle2) {
            g2 = i;
        }
    }
    if (g1 != nullptr && g2 != nullptr) {
        cout<<"_1_";
        Student *s = g1->searchStudent(id);
        if (s != nullptr) {
            cout<<"_2_";
            g2->addStudent(s);
            g1->exclude(id);
        }
    }
}

void Deanery::exclude() {
    for(auto i:groups) {
        for(auto j:i->getStudents()) {
            if(j->averageMark() <= 2) {
                i->exclude(j->getId());
            }
        }
    }
}

void Deanery::exportData(string name) {
    ofstream myfile;
    myfile.open(name);
    if (myfile.is_open()) {
        for (auto i:groups) {
            myfile << i->getTitle() << "   " << i->getSpec() << "\n head:" << i->getHead()->getFio() << endl;
            for (auto j:i->getStudents()) {
                myfile << "  " << j->getId() << "   " << j->getFio() << endl;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Deanery::takeHeaders() {
    for(auto i:groups) {
        i->takeHead();
    }
}

void Deanery::printData() {
    for(auto i:groups) {
        std::cout<<i->getTitle()<<"   "<<i->getSpec()<<endl;
        for(auto j:i->getStudents()) {
            std::cout<<"  "<<j->getId()<<"   "<<j->getFio()<<endl;
        }
    }
}

int Deanery::stringToInt(const string& word) {
    int i;
    try{
        i = stoi(word);
        //cout<<"   strToInt="<<i<<"   ";
    }
    catch (std::invalid_argument const &e) {
        cout<<"Wrong!!! Invalid input";
    }
    catch (std::out_of_range const &e) {
        cout<<"Wrong!!! Overflow";
    }

    return i;
}



