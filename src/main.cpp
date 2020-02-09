#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Group.h"
#include "Student.h"
#include "Dean.h"
using namespace std;



int main() {
    string students_path = "../text/students.txt";
    string generated_students_path = "../text/FIOS.txt";
    string groups_path = "../text/groups.txt";
    string deanery_path = "../text/deanery.txt";
    
    ifstream in(generated_students_path);
    ofstream out_students(students_path);
    ofstream out_groups(groups_path);
    ofstream out_deanery(deanery_path);

    if (in.is_open())
    {
        string student;
        int i = 1;
        string specs[] = {"ПИ","ЭКОНОМ","БИ","ПМИ","ЮРИСТ"};
        map <string,vector<int>> groups;

        while (getline(in, student))
        {
            string spec = specs[rand() % 5];
            groups[spec].push_back(i);
            out_students << student << ":" << i++ << ":" << spec << ":default" <<endl;
        }
        for (const auto& group : groups) {
            out_groups << group.first;
            for (auto id : group.second){
                out_groups << ":" << id;
            }
            out_groups << '\n';
        }

        string tmp_string;
        for (const auto& spec : specs)
            tmp_string += (tmp_string.empty() ? "" : ":") + spec;

        out_deanery << tmp_string;
    }

    out_deanery.close();
    out_students.close();
    out_groups.close();
    in.close();

    auto dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    dean->addGrades(2);
    dean->chooseHeadman();
    dean->migrateStudent("ЮРИСТ",99,"ЭКОНОМ");
    dean->expelStudents();
    map<string,vector<vector<string>>> dataMap;
    dean->showData(dataMap);
    for (auto group:dataMap){
        cout<<group.first<<endl;
        for (auto student:group.second){
            cout<<student[0]<<" "<<student[1]<<" "<<student[2]<<endl;
        }
        cout<<endl;
    }
    bool marksAdded = false;
    for (auto group:dataMap){
        for (auto student :group.second){
            if (stoi(student[2]) > 0){
                marksAdded = true;
            }
        }
    }
    cout<<marksAdded;
    dataMap.clear();
    dean->saveFiles(deanery_path,groups_path,students_path);

    return 0;
}
