#ifndef GROUP_H
#define GROUP_H
#include "mainInc.h"
class Student;
class Group
{
    private:
        std::string title;// - название группы
        std::string spec;// - специальность
        std::vector<Student*> students;// - вектор ссылок на студентов
        Student* head;// - ссылка на старосту (из членов группы)
    public:
        Group();
        Group(std::string title){this->title = title;};
        std::string getTitle(){return this->title;};
        std::string getSpec(){return this->spec;};
        Student* getHead(){return this->head;};
        void setSpec(std::string spec){this->spec = spec;};
        void addStudent(Student* newStudent);
        void assignHead();
        int getMidMark();
        void deleteStudent(Student* st);

        Student* findStudent(std::string name);
        Student* findStudent(unsigned int id);

        void printStList();
        virtual ~Group();
        std::vector<Student*> getStudList(){return this->students;};
};

#endif // GROUP_H
