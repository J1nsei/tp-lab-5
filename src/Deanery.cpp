#include "Deanery.h"

Deanery::Deanery() {}

void Deanery::creationOfGroups(std::string fileName) 
{
    std::ifstream file;
    file.open(fileName);
    if (file) 
    {
        std::string s;
        while (!file.eof())
        {
            getline(file, s);
            //std::cout << s.substr(0, s.find(' ')) << s.substr(s.find(' ')+1, s.length()) <<"\n";
            Group gr(s.substr(0, s.find(' ')), s.substr(s.find(' ')+1, s.length()));
            groups.push_back(&gr);
        }
    }
}


Deanery::~Deanery()
{
}