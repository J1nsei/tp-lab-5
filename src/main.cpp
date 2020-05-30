//
// Created by fiskirton on 10.02.2020.
//

#include <string>
#include <iostream>
#include <helper.h>
#include "Deanery.h"

using namespace std;

int main(){

    auto * d = new Deanery("../data/students.csv", "../data/groups.csv");

    for (int i = 0; i < 10; ++i) {
        d->addRandomMarks();
    }

    cout << d->getStatistics() << endl;

    d->excludeStudent(25);
    d->excludeStudent(1);
    d->transferStudent(2, "18ЭК-4");

    cout << d->getStatistics() << endl;

    delete d;

    return 0;

}
