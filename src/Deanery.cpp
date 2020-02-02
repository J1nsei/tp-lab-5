#include "Deanery.h"
#include "Group.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

void Deanery::importStudents(string name, auto g) {
    int id = 0;
    string fio;
    ifstream myfile(name);
    if (myfile.is_open())
    {
        while (! myfile.eof() ) {
            string line;
            getline(myfile, line);
            string delimiter = " ";
            int pos = 0;
            while ((pos = line.find(" ") != std::string::npos)) {
                string word = line.substr(0, pos);
                cout<<word;
                line.erase(0, pos + delimiter.length());
                if(id == 0) {
                    id = stringToInt(word);
                    id++;
                }
                else {
                    fio += word;
                }
            }
            fio += line;
            cout<<line;
            groups[0].addStudent(id, fio);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Deanery::importGroup(string name, string groupName) {
    for(auto i:groups) {
        if(i.getTitle == groupName) {
            importStudents(name, i);
        }
    }
}

void Deanery::addRandomMark() {
    srand(static_cast<unsigned int>(time(0)));
    for(auto i:groups){
        for(auto j:i.students) {
            for(auto k:j.marks) {
                k.addMark(1 + rand() % 5)
            }
        }
    }
}

void Deanery::getStatistic() {
    for(auto i:groups) {
        std::cout << i.averageMark();
    }
    for(auto i:groups) {
        for (auto j:i.getStudents) {
            std::cout<<j.averageMark();
        }
    }
}

void Deanery::transfer(int id, string t1, string t2) {
    Group g1("", ""), g2("","");
    for(auto i:groups) {
        if(i.getTitle() == t1) {
            Group g1 = i;
        }
        if(i.getTitle() == t2) {
            Group g2 = i;
        }
    }
    g2.addStudent(g1.searchStudent(id));
    g1.exclude(id);
}

void Deanery::exclude() {
    for(auto i:groups) {
        for(auto j:i.students) {
            if(j.averageMark() <= 2) {
                i.exclude(j);
            }
        }
    }
}


void Deanery::exportData(string name) {
    ofstream myfile;
    myfile.open(name);
    for(auto i:groups) {
        myfile<<i.getTitle()<<"   "<<i.getSpec<<"   "<<i.getHead().getFio()<<endl;
        for(auto j:i.getStudents) {
            myfile<<j.getId<<"   "<<j.getFio<<endl;
        }
    }
    myfile.close();
}

void Deanery::takeHeaders() {
    for(auto i:groups) {
        i.takeHead();
    }
}

void Deanery::printData() {
    for(auto i:groups) {
        std::cout<<i.getTitle()<<"   "<<i.getSpec<<"   "<<i.getHead().getFio()<<endl;
        for(auto j:i.getStudents) {
            std::cout<<j.getId<<"   "<<j.getFio<<endl;
        }
    }
}

int Deanery::stringToInt(string word) {
    try{
        int i = stoi(word);
        cout<<"   strToInt="<<i<<"   ";
    }
    catch (std::invalid_argument const &e) {
        cout<<"Wrong!!! Invalid input";
    }
    catch (std::out_of_range const &e) {
        cout<<"Wrong!!! Overflow";
    }

    return 0;
}
