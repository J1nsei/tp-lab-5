//
// Created by Илья Соловьёв on 22.01.2020.
//

#include "Deanery.h"
#include "iostream"
#include "fstream"
#include "Group.h"
#include "Student.h"
#include <algorithm>


//конструктор - заполнение всех данных
Deanery::Deanery() {

    //заполнение групп
    std::string line;
    std::ifstream in("../src/groups.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            int i = 0;
            while (line[i] != ' ') {
                i++;
            }
            auto *newGroup = new Group(line.substr(0, i), line.substr(i + 1, line.size() - i - 1));
            this->groups.push_back(newGroup);
        }
    }
    in.close();

    srand(time(0));

    //заполенение струдентов
    int numb=-1;
    int numbGroups=groups.size();
    std::ifstream in2("../src/students.txt");
    if (in2.is_open()) {
        while (getline(in2, line)) {
            numb++;
            int numbGroup = numb%numbGroups;
            auto *newStudent = new Student(id++, line);

            newStudent->enrollInGroup(groups[numbGroup]->title, this);
        }
    }
    in2.close();

    addMarks();

    for (auto &group : groups) {
        setHead(group->title);
    }
}

//Поиск группы по названию
Group *Deanery::findGroup(const std::string &title) {
    for (auto &group : groups) {
        if (group->title == title) {
            return group;
        }
    }
    return nullptr;
}

Student *Deanery::findStudent(const std::string &fio) {
    for (auto &group : groups) {
        if (group->findFIO(fio) != nullptr) {
            return group->findFIO(fio);
        }
    }

    return nullptr;
}

void Deanery::addMarks() {
    for (auto &group : groups) {
        for (auto &student : group->students) {
            int numMarks;
            numMarks = rand() % 20;
            for (int k = 0; k < numMarks; k++) {
                int mark;
                mark = rand() % 11;
                student->addMark(mark);
            }
        }
    }
}

void Deanery::setHead(const std::string &title) {
    for (auto &group : groups) {
        if (group->title == title) {
            group->newHead();
            break;
        }
    }
}

void Deanery::getStatistics() {
    for (auto &group : groups) {
        std::cout << "\n\n\t" << group->title << std::endl;
        Student *head = group->head;
        std::cout << "\tHEAD: ID: " << head->id << " FIO: " << head->fio << " - AVERAGE MARK: "
                  << head->calculateAveregeMark() << std::endl;
        std::cout << "\tAVERAGE GROUP MARK: " << group->averegeGroupMark() << std::endl;

        std::vector<std::pair<Student *, double>> studentsForStatistics;


        for (auto &student : group->students) {
            if (head != student) {
                studentsForStatistics.emplace_back(student, student->calculateAveregeMark());
            }
        }

        sort(studentsForStatistics.rbegin(), studentsForStatistics.rend(),
             [](const std::pair<Student *, double> &left, const std::pair<Student *, double> &right) {
                 return left.second < right.second;
             });

        for (auto &studentsForStatistic : studentsForStatistics) {
            std::cout << "ID: " << studentsForStatistic.first->id << " FIO: " << studentsForStatistic.first->fio
                      << " - AVERAGE MARK: " << studentsForStatistic.second
                      << std::endl;
        }
    }
}


void Deanery::moveStudent(std::string fio, std::string fromGroupTitile, std::string toGroupTitle) {
    Group* from = findGroup(fromGroupTitile);
    Group* to = findGroup(toGroupTitle);
    Student* student = findStudent(fio);
    int ind = -1;
    for (int i = 0; i < from->students.size(); i++) {
        if (from->students[i] == student) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        std::cout << "Error - student not found" << std::endl;
    } else {
        from->students.erase(from->students.begin() + ind);
        to->addStudent(student);
        student->group=to;

        if (from->head == student) {
            this->setHead(from->title);
        }
    }
}

void Deanery::cickStudent(std::string fio) {
    Student *student = findStudent(fio);
    Group *group = student->group;
    int ind = -1;
    for (int i = 0; i < group->students.size(); i++) {
        if (group->students[i] == student) {
            ind = i;
            break;
        }
    }
    group->students.erase(group->students.begin() + ind);
    if (group->head == student) {
        this->setHead(group->title);
    }

    delete student;
}

void Deanery::addStudent(std::string fio, std::string groupTitle) {
    Student *newStudent = new Student(id++, fio);
    newStudent->enrollInGroup(groupTitle,this);
}


Deanery::~Deanery(){
    for(auto group: groups) {
        for (auto student: group->students){
            delete student;
        }
        delete group;
    }
}