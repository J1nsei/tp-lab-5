#include "Group.h"
#include <numeric>

Group::Group(std::string title, std::string spec){ // создание группы с указанием названия
    this->title = title;
    this->spec = spec;
}

void Group::addStudent(Student* student){ // добавление студента
    this->students.push_back(student);
}

void Group::changeHead(Student* head){ // избрание старосты
    this->head = head;
}

Student* Group::findStudentByID(int id){ // поиск студента по ИД
    for (Student* student: this->students){
        if (student->getID() == id){
            return student;
        }
    }
    return nullptr;
}

Student* Group::findStudentByName(std::string fio){ // поиск студента по имени
    for (Student* student: this->students){
        if (student->getFIO() == fio){
            return student;
        }
    }
    return nullptr;
}
float Group::getAverageMark() { // вычисление среднего балла в группе
    int sum = 0;
    for (Student* student: this->students){
        sum += student->getAverageMark();
    }
    sum = sum / this->students.size();
    return sum;
}

void Group::deleteStudent(int id) { // исключение студента из группы
    int j = 0;
    for (auto i = this->students.begin(); i != this->students.end(); i++, j++){
        if (students[j]->getID() == id) {
            this->students.erase(i);
            break;
        }
    }
}

std::string Group::getTitle() {
    return this->title;
}

std::string Group::getSpec() {
    return this->spec;
}

std::vector<Student*> Group::getStudents() {
    return this->students;
}

Student* Group::getHead(){
    return this->head;
}
