
//
// Created by Anton Korkunov on 22/01/2020.
//
#include "Deanery.h"
#include <fstream>

using namespace std;

Deanery::Deanery(){

};
void Deanery::createStudents(vector<string> StudNAME, vector <Student> *StudentList){
    for (int i=0;i<StudNAME.size();i++){
        (*StudentList).emplace_back(Student());
        (*StudentList)[i].create(StudNAME[i],i);
    }
};
void Deanery::createGroups(vector<string> GroupsNAME, vector <Group> *GroupList){
    string spec = "Aplied math and inf";
    for (int i=0;i<GroupsNAME.size();i++){
        (*GroupList).push_back(Group());
        (*GroupList)[i].create(GroupsNAME[i],spec);
       // groups.push_back(&(*GroupList)[i]);
    }
    for (int i=0;i<GroupsNAME.size();i++){
        groups.push_back(&(*GroupList)[i]);
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
void Deanery::StudSwap(Student* candidat, Group* Gto){
     Group * Gfrom = candidat->getGroup();
     string tmpName = candidat->getName();
     Gfrom->findS(tmpName);
     Gto->addstud(candidat);
     candidat->ingroup(Gto);
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

void Deanery::fillupGRs(vector <Student> *StudentList){
    for (int i=0;i<(*StudentList).size();i++){
       if(i<10){
           groups[0]->addstud(&(*StudentList)[i]);
       }
      else  if(i>10 and i<20){
           groups[1]->addstud(&(*StudentList)[i]);
        }
       else if(i>20){
           groups[2]->addstud(&(*StudentList)[i]);
        }
    }
};