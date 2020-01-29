//
// Created by Egor on 22.01.2020.
//
#include <iostream>
#include <vector>
#include <windows.h>
#include "dean.h"
#include "student.h"

using namespace std;

int Student::static_ID = 0;

int main()
{
    system("chcp 65001");

    cout << "**********************************************************" << endl;
    cout << "Создание деканата..." << endl;
    Dean* dean = new Dean("students.txt");

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Запрос информации по группам:" << endl;
    dean->ShowShortStatistics();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Выставление оценок за экзамен по мат анализу..." << endl;
    dean->AddRandomMarksToStudents();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Выставление оценок за экзамен по программированию..." << endl;
    dean->AddRandomMarksToStudents();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Исключение студентов после первого семестра..." << endl;
    dean->CheckForKick();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Переизбрание старост..." << endl;
    dean->ChangeHeads();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Запрос информации по группам:" << endl;
    dean->ShowShortStatistics();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Выставление оценок за экзамен по английскому языку..." << endl;
    dean->AddRandomMarksToStudents();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Выставление оценок за экзамен по ассемблеру..." << endl;
    dean->AddRandomMarksToStudents();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Исключение студентов после второго семестра..." << endl;
    dean->CheckForKick();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Переизбрание старост..." << endl;
    dean->ChangeHeads();

    Sleep(3000);

    cout << "**********************************************************" << endl;
    cout << "Полная статистика:" << endl;
    dean->ShowStatistics();
    return 0;
}

