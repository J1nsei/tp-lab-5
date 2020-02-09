#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//#include <Windows.h>
#include "Dean.h"
#include "Group.h"
#include "Student.h"
void output(Dean& hei){
    //std::fstream out("out.txt");
    std::vector<Group> groups = hei.getGroups();
    for (auto& x : groups)
        if(x.getHeadman() == nullptr && x.getStudents().size())
            x.newHeadman();
    for (auto & x : groups){
        std::cout << x.getName() << " " << x.getSpecialty() << " Староста - " << ((x.getHeadman() != nullptr) ? x.getHeadman()->getName() : "Нет") << std::endl;
        auto students = x.getStudents();
        for (auto & y : students){
            std::cout << y.getName() << std::endl;
        }

        std::cout << std::endl << std::endl << std::endl;
    }
}

int main(){
    //system("chcp 1251");
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    std::fstream students("students2.txt");
    std::fstream groups_names("Groups_names.txt");
    Dean hse;
    hse.startCourse(students, groups_names);
    std::vector<Group> groups = hse.getGroups();





    for(auto group : hse.getGroups())
    {
        std::cout << group.getName() << " - " << group.getSize() << std::endl;
    }
    //hse.createGroup("18БИ-3", "Бизнес-Информатика");
    hse.addStudent("Илюха");
    hse.addStudent("Ванек");
    hse.addStudent("Игорь");
    hse.addStudent("Валентин");
    hse.addStudent("Серый");
    //output(hse);

    for(auto group : hse.getGroups())
    {
        std::cout << group.getName() << " - " << group.getSize() << std::endl;
    }
    for (int i = 0; i < 5; i++)
        hse.testStudents();
    //output(hse);
    hse.clearing(4);

    for(auto group : hse.getGroups())
    {
        std::cout << group.getName() << " - " << group.getSize() << std::endl;
    }


    return 0;
}