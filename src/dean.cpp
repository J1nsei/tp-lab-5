//
// Created by Mikhail on 16.01.2020.
//

#include <student.h>
#include <sstream>
#include <dean.h>
#include <fstream>
#include <assert.h>

using std::stringstream;

vector<string> split(const string &s, char del){
    vector<string> words;
    stringstream ss(s);
    string currentWord;
    while(getline(ss, currentWord, del))
        words.push_back(currentWord);
    return words;
}

void Dean::generateStudents() {
    std::ifstream fin("../res/Students.txt");
    string input;
    while(getline(fin, input)){
        vector<string> inputParts = split(input, ':');
        string studentName;
        for(const auto& x: inputParts)
            studentName += x + " ";
        studentNames.push_back(studentName);
    }
    fin.close();
}

void Dean::generateGroups() {
    std::ifstream fin("../res/Groups.txt");
    string input;
    while(getline(fin, input)){
        vector<string> inputParts = split(input, ':');
        vector<string> titSpec;
        for(const auto& x: inputParts) {
            titSpec.push_back(x);
        }
        assert(titSpec.size() > 1);
        groupNames.push_back({titSpec[0], titSpec[1]});
    }
    fin.close();
}

void Dean::addMarks() {
    for(auto group: groups){
        for(auto student: group->getStudents()){
            int mark = rand() % 60;
            if(mark < 60 && mark >= 50){
                student->addMark(5);
                continue;
            }
            if(mark < 50 && mark >= 30){
                student->addMark(4);
                continue;
            }
            if(mark < 30 && mark >= 10){
                student->addMark(3);
                continue;
            }
            student->addMark(2);
        }
    }
}

Dean::Dean() {
    generateGroups();
    generateStudents();
    for(auto groupName: groupNames) {
        groups.push_back(new Group(groupName.first, groupName.second));
    }
    int cnt = 0;
    for(auto studentName: studentNames) {
        students.push_back(new Student(id++, studentName));
        groups[cnt++]->addStudent(students.back());
        cnt %= groups.size();
    }
}

Dean::~Dean(){
    for(auto student: students) delete student;
    for(auto group: groups) delete group;
}

void Dean::removeStudent(Student *student) {
    for (auto group: groups) {
        group->dropStudent(student);
    }
    students.remove_if([&](Student* currentStudent){
        return currentStudent == student;
    });
    delete student;
}

void Dean::migrate(Group *from, Group *to, int ID = -1, string FIO = "") {
    if(ID == -1 && FIO == "")
        return;;
    Student* currentStudent = ID == -1 ? from->findStudent(ID) : from->findStudent(FIO);
    from->dropStudent(currentStudent);
    to->addStudent(currentStudent);
}

vector<vector<pair<int, int> > > Dean::stats() {
    vector<vector<pair<int,int> > > stat;
    for(auto group: groups){
        vector<pair<int,int> > groupStat;
        for(auto student: group->getStudents()){
            pair<int,int> studentStat(0, 0);
            for(auto mark: student->getMarks()){
                if(mark < 3) studentStat.second++;
                else studentStat.first++;
            }
            groupStat.emplace_back(studentStat);
        }
        stat.emplace_back(groupStat);
    }
    return stat;
}

void Dean::pickHeads() {
    for(auto group: groups){
        group->setHead();
    }
}

void Dean::printData() {
    std::cout << "\nINFO\n";
    int sum = 0;
    for(auto group: groups){
        std::cout << "Groupname: " << group->getTitle() << " Spec: " << group->getSpec() << '\n';
        for(auto student: group->getStudents()){
            std::cout << "\tFIO: " << student->getFIO() << '\n';
        }
        int cnt = group->getStudents().size();
        std::cout << "\tTotal in group: " << cnt << '\n';
        sum += cnt;
    }
    std::cout << "Total: " << sum << '\n';

}

void Dean::deduction() {
    list<Student*> onDrop;
    for(auto student: students){
        int cnt = 0;
        for(auto x: student->getMarks()){
            if(x < 3) cnt++;
        }
        if(cnt > student->getMarks().size() / 2) onDrop.emplace_back(student);
    }
    for(auto student: onDrop) removeStudent(student);
}

list<Student *> Dean::getStudents() {
    return students;
}

vector<Group *> Dean::getGroups() {
    return groups;
}
