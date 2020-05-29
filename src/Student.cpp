#include "Student.h"

Student::Student()
{
    //ctor
}

Student::Student(string name, int id)
{
    this->fio = name;
    this->id = id;
}

int Student::getMidMark(){
    if(this->marks.size() == 0){
        return 0;
    }
    int sum = 0;
    for(auto i:this->marks){
        sum += i;
    }
    return sum/this->marks.size();
}
