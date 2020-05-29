
//
// Created by Anton Korkunov on 22/01/2020.
//
#include "Deanery.h"
#include <fstream>

using namespace std;

Deanery::Deanery(){

};
void Deanery::createStudents(vector<string> StudNAME){
    if(groups.size()!=0) {
        for (int i = 0; i < StudNAME.size(); i++) {
            Student *temp = new Student();
            temp->create(StudNAME[i], i);
            if (i < 10) {
                groups[0]->addstud(temp);
            } else if (i >= 10 and i <= 20) {
                groups[1]->addstud(temp);
            } else if (i > 20) {
                groups[2]->addstud(temp);
            }
        }
    }
    else  cout<<"create groups first "<<"\n";

};
void Deanery::createGroups(vector<string> GroupsNAME, string spec){
    for (int i=0;i<GroupsNAME.size();i++){
       Group *temp=new Group();
       temp->create(GroupsNAME[i],spec);
       groups.push_back(temp);
    }

};
void Deanery::makeMarks(){
    for (int i=0;i<groups.size();i++){
        groups[i]->giveMarks();
    }
};
int Deanery::getStat(){
    for (int i=0;i<groups.size();i++){
        double OUTtmp = groups[i]->cntBall();
        cout<<"Group "<< i+1 << " Statistic: "<<"\n";
        cout<<OUTtmp<<"\n";
    }
};
void Deanery::StudSwap(string candidat, string Gto) {

    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->findS(candidat)) {
            Student *tmp = groups[i]->getStudent(candidat);
            groups[i]->findStodel(candidat);
            for (int i = 0; i < groups.size(); i++) {
                if (groups[i]->getName() == Gto) {
                    groups[i]->addstud(tmp);
                    tmp->ingroup(groups[i]);
                }
            }
        }
    }
};
void Deanery::DelStud(double aver){
    for (int i=0;i<groups.size();i++){
          groups[i]->drop(aver);
    }
};
void Deanery::SaveData(){
    std::ofstream out;
    out.open("/Users/antonkorkunov/CLionProjects/lab5/filetoOUT");
    string spec = "Aplied math and inf";
    out<<"Spec: "<< spec <<"\n"<<"\n";
    for (int i=0;i<groups.size();i++){
        out<< groups[i]->getName()<<":"<<"\n";
        out<< groups[i]->WriteStudents()<<"\n";
    }
};
void Deanery::HeadChoice(){
    for (int i=0;i<groups.size();i++){
        groups[i]->chHead();
        }
};
void Deanery::OutPut(){
    string spec = "Aplied math and inf";
    cout<<"Spec: "<< spec <<"\n";
    for (int i=0;i<groups.size();i++){
        cout<< groups[i]->getName()<<":"<<"\n";
        cout<< groups[i]->WriteStudents()<<"\n";
    }
};

int Deanery::GRsize(int i){
return groups[i]->getSize();
};
