//
// Created by Илья on 026 26.01.20.
//

#include <iostream>
#include <student.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Student* st = new Student(11, "aaa");
    st->addMark(1);
    st->addMark(2);
    st->addMark(10);
    cout << "Average mark: " << st->calcAverageMark();
    return 0;
}