//
// Created by Илья Соловьёв on 15.01.2020.
//

#include "Student.h"
#include "Group.h"

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
}

//вписывает студента в группу
void Student::enrollInGroup(std::string title, Deanery *deanery) {
    //ищет группу по названию
    Group *groupToEnroll = deanery->findGroup(title);
    groupToEnroll->addStudent(this);
    this->group = groupToEnroll;

}

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

double Student::calculateAveregeMark() {
    int sum = 0;
    for (int i = 0; i < marks.size(); i++) {
        sum += marks[i];
    }
    if (marks.size() == 0) {
        return 0;
    } else {
        return sum / marks.size();
    }
}
