#include <iostream>
#include "Deanery.h"
#include "Student.h"

int main() {
    Deanery* dean = new Deanery();
    Group* group = new Group("18Pi1", "SE");
    Group* group2 = new Group("18Pi2", "SE");
    Student* student = new Student(12, "Mikle");

    //Student
    student->setGroup(group);
    student->addMark(5);
    cout<<"Average Mark = "<<student->averageMark()<<endl;
    cout<<"Student Id = "<<student->getId()<<endl;
    cout<<"Student Fio = "<<student->getFio()<<endl;

    //Group
    group->addStudent(student);
    group->takeHead();
    cout<<"Adress of student object1 = "<<group->searchStudent(student->getId())<<endl;
    cout<<"Adress of student object2 = "<<group->searchStudent(student->getFio())<<endl;
    group->getStudents();
    group->exclude(student->getFio());
    group->addStudent(student);
    group->exclude(student->getId());
    group->addStudent(student);
    cout<<"Group Spec = "<<group->getSpec()<<endl;
    cout<<"Group Title = "<<group->getTitle()<<endl;
    group->getHead();
    group->averageMark();

    //Deanery
    dean->addGroup(group);
    dean->addGroup(group2);
    cout<<endl<<endl;
    dean->printData();
    dean->addRandomMarks();
    dean->getStatistic();
    dean->takeHeaders();
    dean->transfer(student->getId(), group->getTitle(), group2->getTitle());
    cout<<"Adress of student object1 = "<<group2->searchStudent(student->getId())<<endl;
    cout<<"Search student by Id  = "<<group2->searchStudent(student->getId())->getId()<<endl;
    group2->addStudent(student);
    cout<<"Search student by Id = "<<group2->searchStudent(student->getId())->getId()<<endl;
    cout<<"test getFio and getId = "<<student->getFio()<<" "<<student->getId()<<endl;
    group->addStudent(student);
    dean->importFile("D:\\C++\\untitled\\studentExamle.txt");
    group->addStudent(student);
    cout<<endl;
    dean->printData();
    dean->importFile("D:\\C++\\untitled\\groupExamle.txt", "19Pi3", "SE");
    cout<<endl;
    dean->printData();
//    dean->exportData("D:\\C++\\untitled\\Example.txt");
    return 0;
}

/*TODO

 +   1. создание студента с указанием ИД и ФИО
 +   2. зачисление в группу
 +   3. добавление оценки
 +   4. вычисление средней оценки


 +   5. создание группы с указанием названия
 +   6. добавление студента
 +   7. избрание старосты
 +   8. поиск студента по ФИО или ИД
 +   9. вычисление соеднего балла в группе
 +   10. исключение студента из группы


 +   11. создание студентов на основе данных из файла
    12. создание групп на основе данных из файла
 +   13. добавление случайных оценок студентам
 +   14. получение статистики по успеваемости студентов и групп
 +   15. перевод студентов из группы в группу
 +   16. отчисление студентов за неуспеваемость
    17. сохранение обновленных данных в файлах
 +   18. инициация выборов старост в группах
 +   19. вывод данных на консоль


*/