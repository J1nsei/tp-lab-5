#include <iostream>
#include <cstdio>
#include "Student.h"
#include "Group.h"
#include <random>
#include <sstream>
#include <vector>
#include <fstream>
#include "Deanery.h"


using namespace std;



std::vector<std::string> split(const std::string& s, char delimiter){
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while(std::getline(tokenStream,token,delimiter))
        tokens.push_back(token);
    return tokens;
}

int main() {

    vector<string> STDN;

    ifstream fs1("/Users/antonkorkunov/CLionProjects/lab5/students", ios::in);
    if(!fs1) return 2;
  //  system("chcp 1251");
    while(!fs1.eof()){
        std::string buf;
        getline(fs1,buf,'\n');
         STDN.push_back(buf);
        vector<string> data=split(buf,':');
        for(auto s : data)
            std::cout << s << " ";
        std::cout << std::endl;
    }
fs1.close();

    vector<string> GRPS;

    ifstream fs2("/Users/antonkorkunov/CLionProjects/lab5/groups", ios::in);
    if(!fs2) return 2;
  //  system("chcp 1251");
    while(!fs2.eof()){
        std::string buf;
        getline(fs2,buf,'\n');
        GRPS.push_back(buf);
        vector<string> data=split(buf,':');
        for(auto s : data)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    fs2.close();

 // vector <Student> StudentList;
   // StudentList.push_back(Student());
//  vector <Group> GroupList;
 Deanery D1;
 D1.createGroups(GRPS);//, &GroupList);
 D1.createStudents(STDN);//, &StudentList);

// D1.fillupGRs(&StudentList);
for(int i=0; i<=10;i++)  D1.makeMarks();

D1.HeadChoice();

D1.getStat();

D1.DelStud(3.59);

//D1.getStat();

D1.OutPut();

D1.StudSwap("Лужкова Владлена Гавриловна", "AMI 2");

D1.OutPut();
//D1.OutPut();

D1.SaveData();
Deanery D2;
    std::vector<string> STDN1{"Maxim","Jora"};
    std::vector<string> GRP1{"AMI 2","EC 4"};
    D2.createGroups(GRP1);
    D2.createStudents(STDN1);
    D2.StudSwap("Jora","EC 4");



return 0;
}