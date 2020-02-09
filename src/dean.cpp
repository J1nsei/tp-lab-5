//
// Created by Оксана on 15.01.2020.
//
#include <sstream>
#include <fstream>
#include <assert.h>
#include <dean.h>
#include <student.h>
using namespace std;

vector<string> split(const string &s, char del){
    vector<string> words;
    stringstream ss(s);
    string currentWord;
    while(getline(ss, currentWord, del))
        words.push_back(currentWord);
    return words;
}

void Dean::Add_students() {
    ifstream fin("../res/Names.txt");
    string input;
    while(getline(fin, input)){
        vector<string> inputParts = split(input, ' ');
        string name;
        for(const auto& x: inputParts)
            name += x + " ";
        Names_of_students.push_back(name);
    }
    fin.close();
}
void Dean::Add_groups() {
    std::ifstream fin("../res/Groups.txt");
    string input;
    while(getline(fin, input)){
        vector<string> inputParts = split(input, ':');
        vector<string> titSpec;
        for(const auto& x: inputParts) {
            titSpec.push_back(x);
        }
        assert(titSpec.size() > 1);
        Names_of_groups.push_back({titSpec[0], titSpec[1]});
    }
    fin.close();
}
Dean::Dean() {
    Add_groups();
    Add_students();
    for(auto Names_of_group : Names_of_groups) {
        groups.push_back(new Group(Names_of_group.first, Names_of_group.second));
    }
    int cnt = 0;
    for(auto Name_of_student : Names_of_students) {
        students.push_back(new Student(id++, Name_of_student));
        groups[cnt++]->Add_student(students.back());
        cnt %= groups.size();
    }
}

Dean::~Dean(){
    for(auto student: students) delete student;
    for(auto group: groups) delete group;
}

void Dean::Add_marks(string Name_of_group, int count) {
    for (auto *group : groups) {
        if (group->Get_title() == Name_of_group) {
            for(auto *student : group->Get_students()){
                for (int i = 0; i < count; i++) {
                    unsigned int mark = rand() % 10;
                    student->Add_mark(mark);
                }
            }
        }
    }
}

vector<vector<pair<int, int> > > Dean::Get_state() {
    vector<vector<pair<int,int>>> state;
    for(auto group: groups){
        vector<pair<int,int> > State_of_group;
        for(auto student: group->Get_students()){
            pair<int,int> State_of_student(0, 0);
            if(student->Calc_aver_mark() < 3.5){

            }
            groupStat.emplace_back(studentStat);
        }
        stat.emplace_back(groupStat);
    }
    return stat;
}

void Dean::Check_and_delete_students(){
    for (auto& group : groups) {
        for(auto *student : group->Get_students()) {
            if (student->Calc_aver_mark() < 2.5) {
                group->Exclusion_student(student->Get_id);
            }
        }
    }
}


Group* Dean::Search_of_group(string Name_of_group) {
    for (auto * group : groups) {
        if (group->Get_title() == Name_of_group)
            return group;
    }
    return nullptr;
}

void Dean::Choose_head(string group_name) {
    Group* group = Search_of_group(group_name);
    group->Election_of_the_head(rand() % group->Get_size());
}

void Dean::Print_date() {
    for (auto & group : groups) {
        unsigned int size = group->Get_size();
        cout << "Group: " << group->Get_title() << endl;
        output << "Amount of students: " << size << endl;
        output << "Average mark: " << group->Calc_aver_mark_in_group() << endl;
        output << "The head: " << group->Get_head()->Get_id() << ". " << group->Get_head()->Get_fio() << endl;
        output << "Specialty: " << group->Get_spec()m<< endl;
        for (auto* student : group->Get_students()){
            output << student->Get_id() << "  " << student->Get_fio() << endl;
            output << '[';
            for (auto mark : student->Get_marks())
                output << " " << mark << " ";
            output << ']' << endl;
        }
        output << endl;
    }

}

void Dean::Transfer_of_student(string name, string from, string to){
    Group* group_from = Search_of_group(from);
    Group* group_to = Search_of_group(to);
    Student* student = group_from->Search_of_student(name);
    student->Set_group(group_to);
    group_from->Exclusion_student(name);
    group_to->Add_student(student);

}



