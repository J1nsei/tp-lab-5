#include <algorithm>
#include "Deanery.h"

Deanery::Deanery() {
    srand(time(nullptr));
}

void Deanery::getActualDataFromFile() {
    std::string line;
    std::ifstream in(fileName);

    int id = 0;

    if (in.is_open()) {
        while (getline(in, line)) {

            std::string studentFio;
            std::string groupTitle;
            std::string groupSpec;

            parseStudent(line, &studentFio, &groupTitle, &groupSpec);

            id++;

            if (!isGroupExist(groupTitle, groupSpec)) {
                auto *group = new Group(groupTitle, groupSpec);
                groups.push_back(group);
            }

            Group *group = getGroupByTitleAndSpec(groupTitle, groupSpec);
            group->addStudent(new Student(studentFio, group, id));
        }
    }
    in.close();
}

void Deanery::parseStudent(std::string line, std::string *fio, std::string *group, std::string *spec) {
    int type = 0;

    for (int i = 0; i < line.size() - 1; i++) {
        if (line[i] != ' ') {
            if (type == 0) {
                *fio += line[i];
            } else if (type == 1) {
                *group += line[i];
            } else if (type == 2) {
                *spec += line[i];
            }
        } else {
            type++;
        }
    }
}

bool Deanery::isGroupExist(const std::string &title, const std::string &spec) {
    if (groups.empty()) {
        return false;
    } else {
        for (Group *group: groups) {
            if (group->getTitle() == title && group->getSpec() == spec) {
                return true;
            }
        }
    }
    return false;
}

Group *Deanery::getGroupByTitleAndSpec(const std::string &title, const std::string &spec) {
    for (Group *group: groups) {
        if (group->getTitle() == title && group->getSpec() == spec) {
            return group;
        }
    }
    return nullptr;
}

void Deanery::showAllStudents() {
    for (Group *group: groups) {
        std::cout << "\n" << group->getTitle() << " " << group->getSpec() << "\n";
        for (Student *student: group->getStudents()) {
            std::cout << student->getId() << " " << student->getFio() << "\n";
        }
    }
}

void Deanery::addRandomMarkForAllStudents() {

    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            student->addMark(rand() % 6);
        }
    }
}

void Deanery::showStatisticForAllStudents() {
    for (Group *group: groups) {
        std::cout << "\n" << group->getTitle() << " " << group->getSpec() << "\n";
        for (Student *student: group->getStudents()) {
            std::cout << student->getId() << " " << student->getFio() << ". Marks: ";
            for (int mark: student->getMarks()) {
                std::cout << mark << " ";
            }
            std::cout <<" Average: " << student->getAverageMark() << "\n";
        }
    }
}

void Deanery::kickStudentWithMarkLowerThan(double lowerBorder) {
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            if (student->getAverageMark() < lowerBorder) {
                group->kickStudent(student->getId());
            }
        }
    }
}

void Deanery::startRandomElection() {
    for (Group *group: groups) {
        if (!group->getStudents().empty()) {
            group->setHead();
        }
    }
}

std::vector<Group*> Deanery::getGroups() {
    return groups;
}

void Deanery::showGroupsHeads() {
    for (Group* group: groups) {
        if (!group->getStudents().empty()) {
            if (group->getHead() != nullptr) {
                std::cout << group->getTitle() << " " << group->getSpec() << " Head is " << group->getHead()->getFio() << "\n";
            } else {
                std::cout << group->getTitle() << " " << group->getSpec() << " Head is not appoint \n";
            }
        } else {
            std::cout << group->getTitle() << " " << group->getSpec() << " Group is empty \n";
        }
    }
}

void Deanery::transfer(Student* student, Group* group) {

    if (group != student->getGroup()) {
        auto* transferableStudent = new Student(student->getFio(), group, student->getId());
        for (int mark: student->getMarks()) {
            transferableStudent->addMark(mark);
        }
        group->addStudent(transferableStudent);
        student->getGroup()->kickStudent(student->getId());
    }
}

void Deanery::transfer(int id, const std::string& groupTitle, const std::string& groupSpec) {
    Group* toGroup = nullptr;
    Student* transferStudent = nullptr;
    for (Group* group: groups) {
        if (group->getTitle() == groupTitle && group->getSpec() == groupSpec) {
            toGroup = group;
        }
        for (Student* student: group->getStudents()) {
            if (student->getId() == id) {
                transferStudent = student;
            }
        }
    }
    if (toGroup != nullptr && transferStudent != nullptr) {
        transfer(transferStudent, toGroup);
    }
}

void Deanery::saveData() {
    std::ofstream out(fileName);
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            out << student->getFio() << " " << group->getTitle() << " " << group->getSpec() <<";\n";
        }
    }
    out.close();
}