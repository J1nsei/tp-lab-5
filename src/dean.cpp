//
// Created by Egor on 22.01.2020.
//
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "student.h"
#include "group.h"
#include "dean.h"
#include <stdio.h>


bool Dean::IsGroupExist(std::string name)
{
    for (auto group : this->groups)
    {
        if (group->GetTitle() == name)
            return true;
    }

    return false;
}

Dean::Dean(std::string path)
{
    std::ifstream stream_from(path);

    std::string input;
    bool studentReady = false;
    std::string currentStudentName;

    while (std::getline(stream_from, input, '\n'))
    {
        std::string line;
        std::stringstream inputStream(input);

        while (std::getline(inputStream, line, ';'))
        {
            if (!studentReady)
            {
                currentStudentName = line;
                studentReady = true;
                continue;
            }

            auto student = new Student(currentStudentName);

            if (!IsGroupExist(line))
            {
                auto group = new Group(line);
                group->AddStudent(student);
                this->groups.push_back(group);
            }
            else
            {
                for (auto group : this->groups)
                    if (group->GetTitle() == line)
                    {
                        group->AddStudent(student);
                        break;
                    }
            }

            studentReady = false;
        }
    }

    stream_from.close();

    this->AddRandomMarksToStudents();

}

void Dean::AddRandomMarksToStudents()
{
    srand(time(NULL));

    for (auto group : this->groups)
        for (auto student : group->students)
            student->marks.push_back(1 + rand() % 10);
}

void Dean::ChangeHeads()
{
    for (auto group : this->groups)
        group->SetHead();
}

bool Dean::ChangeGroupOfStudent(Group *from, Group *in, int ID)
{
    if (from == in)
        return false;

    for (auto student : from->students)
        if (student->GetID() == ID)
        {
            from->KickStudent(student);
            in->AddStudent(student);
            return true;
        }

    return false;
}

void Dean::CheckForKick()
{
    for (auto group : this->groups)
        for (auto student : group->students)
        {
            if (student->GetAverageMark() < 4)
                group->KickStudent(student);
            delete student;
        }
}

void Dean::ShowStatistics()
{
    std::cout << "Statistics:" << std::endl;

    for (auto group : this->groups)
        for (auto student : group->students)
        {
            std::cout << "***********************************" << std::endl;
            std::cout << "ID: " << student->GetID() << std::endl;
            std::cout << "ФИО: " << student->GetFIO() << std::endl;
            std::cout << "Группа: " << group->GetTitle() << std::endl;
            std::cout << "Средний балл: " << student->GetAverageMark() << std::endl;
        }
    std::cout << "***********************************" << std::endl;
}

void Dean::SaveData()
{
    
}

