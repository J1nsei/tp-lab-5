//
// Created by Sergey Baranenkov on 29.01.2020.
//

#include "Dean.h"
void Dean::createGroups(const string& filename) {
    ifstream in(filename);
    string groupString;
    getline(in,groupString);
    vector <string> splittedGroups = split(groupString,  ':');
    for (const auto& gName:splittedGroups){
        auto newGroup = new Group{gName};
        this->groupNames[gName] = newGroup;
    }
    splittedGroups.clear();
}
void Dean::createStudents(const string& filename) {
    ifstream in(filename);
    string newStudent;
    while(getline(in,newStudent)){
        vector<string> tmp = split(newStudent,':');
        string gName = tmp[2];
        unsigned int id = stoi(tmp[1]);
        string abbr = tmp[0];
        if (groupNames.find(gName)!=groupNames.end()){
            auto studentObj = new Student{id, abbr};
            studentObj->group = groupNames[gName];
            groupNames[gName]->add_student(studentObj);
            if (tmp[3] == "head") {
                studentObj->group->head = studentObj;
            }
            for(auto i=4;i < tmp.size();i++){
                studentObj->add_mark(stoi(tmp[i]));
            }
        }
        tmp.clear();
    }
}

void Dean::addGrades(unsigned int n) {
    for (const auto& group:groupNames){
            for (auto student : group.second->students){
                for (auto i = 0; i<n;i++){
                    student->add_mark(rand()%10);
                }
            }
    }
}

void Dean::expelStudents() {
    for (auto group:groupNames) {
        vector<unsigned int> toKick;
        for (auto student: group.second->students){
            if(student->get_mean() < 4){
                toKick.push_back(student->id);
            }
        }
        for(auto id : toKick){
            delete(group.second->kick_student(id));
        }
        toKick.clear();
    }
}
void Dean::migrateStudent(const string& group_from, unsigned int id, const string& group_to) {
        if (groupNames[group_from] != nullptr && groupNames[group_to] != nullptr){
            auto student = groupNames[group_from]->kick_student(id);
            if (student != nullptr){
                student->group = groupNames[group_to];
                groupNames[group_to]->add_student(student);
            }
        }
}

void Dean::chooseHeadman() {
    for (const auto& group :groupNames){
        auto curgroup = group.second;
        auto gsize = curgroup->students.size();
        if (gsize > 0){
            curgroup->set_head(curgroup->students[rand() % gsize]);
        }
    }
}

void Dean::showData(){
    for (const auto& group: groupNames){
        cout<<group.second->title<<endl;
        if (group.second->head!= nullptr){
            cout<<"head "<<group.second->head->full_name<<endl;
        }
        for(auto student:group.second->students){
            cout<<student->full_name<<" "<<student->id<<" "<<student->get_mean()<<endl;
        }
        cout<<endl;
    }
}

void Dean::saveFiles(const string& deanery_path, const string& groups_path, const string& students_path) {
    ofstream out_students(students_path);
    ofstream out_groups(groups_path);
    ofstream out_deanery(deanery_path);

    if (out_deanery.is_open() && out_groups.is_open() && out_students.is_open()){
        string tmp_string;
        for (const auto& group : groupNames){
            tmp_string += (tmp_string.empty() ? "" : ":") + group.second->title;

            out_groups<<group.second->title;
            for (auto student : group.second->students){
                out_groups<<":" << student->id;

                out_students<<student->full_name<<
                ":"<<student->id<<
                ":"<<student->group->title<<
                ":"<<(student->group->head == student?"head":"default");
                for (auto mark:student->marks){
                    out_students<<":"<<mark;
                }

                out_students<<endl;
            }
            out_groups<<endl;
        }
        out_deanery<<tmp_string<<endl;
    }
    out_deanery.close();
    out_students.close();
    out_groups.close();
}
vector<string>split(const string& s, char delim)
{
    vector <string> elems;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}
