//
// Created by Илья Соловьёв on 15.01.2020.
//


#include "string"
#include "Deanery.h"
#include "Group.h"
#include <iostream>

using namespace std;

int main() {

    Deanery *deanery = new Deanery();

    deanery->getStatistics();

    deanery->moveStudent("Мячина Ева Тарасовна", "19ПМИ-2", "19ПМИ-1");
    deanery->moveStudent("Ланцов Александр Данилевич", "19ПМИ-2", "19ПМИ-1");

    deanery->getStatistics();

    deanery->cickStudent("Ланцов Александр Данилевич");

    deanery->getStatistics();

    deanery->addStudent("Соловьев Илья Максимович", "19ПМИ-2");






    return 0;
}