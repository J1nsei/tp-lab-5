#include "Deanery.h"

int main(int argc, char *argv[]) 
{
    std::cout<<"-------\n";
    std::string fileName = "groups.txt";
    Deanery d;
    d.creationOfGroups(fileName);
    
    return 0;
}