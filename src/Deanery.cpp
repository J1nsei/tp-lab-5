#include "Deanery.h"


Deanery::~Deanery() {

}

Deanery::Deanery() {

}

void Deanery::addRandomMarkForStudents() {
    srand(time(nullptr));
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            student->addMark(rand() % 15);
        }
    }
}

void Deanery::showMarksOfStudents() {
    for (Group* group : groups) {
        for (Student* student : group->getStudents()) {
            std::cout << student->getFio() << " " << group->getTitle() << " ";
            for (int i : student->getMarks()) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }
}

void Deanery::studentTransfer(Student *student, Group *group) {
    student->setGroup(group);
}

void Deanery::kickStudentsWithBadMarks() {
    for (Group* group : groups) {
        for (Student* student : group->getStudents()) {
            if (student->getAverageMark() < 2.49) {
                group->kickStudent(student);
            }
        }
    }
}

void Deanery::startHeadElection() {
    for (Group* group : groups){
        group->chooseHead();
    }
}

void Deanery::showData() {
    for (Group *group: groups) {
        std::cout << "\n" << group->getTitle() << "\n";
        for (Student *student: group->getStudents()) {
            std::cout << student->getId() << " " << student->getFio() << "\n";
        }
    }
}

void Deanery::saveData() {
    std::ofstream out(studentFile);
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            out << student->getFio() << " " << group->getTitle() <<"\n";
        }
    }
    out.close();
}

void Deanery::getDataFromFile() {
    std::string line;
    std::ifstream in(groupFile);

    if (in.is_open()) {
        while (getline(in, line)) {
            Group *group = new Group(line);
            groups.push_back(group);
        }
    }
    in.close();

    int id = 1;
    std::ifstream fin(studentFile);

    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::string title = "";
            std::string fio = "";

            int i = 0;
            while (line[i] != ':') {
                fio += line[i];
                i++;
            }
            i++;
            while (i < line.size()) {
                title += line[i];
                i++;
            }

            for (Group *group : groups) {
                if (group->getTitle() == title) {
                    Student* student = new Student(id, fio, group);
                    group->addStudent(student);
                    id++;
                }
            }
        }
    }
    fin.close();
}

