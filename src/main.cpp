#include "Deanery.h"

int main(int argc, char *argv[]) 
{
    std::cout<<"-------\n";
    std::string fileGroups = "groups.txt";
    std::string fileStudents = "students.txt";
    Deanery d;
    std::cout<<"-------\n";
    d.creationOfGroups(fileGroups);
    std::cout<<"-------\n";
    d.creationOfStudents(fileStudents);
    std::cout<<"-------\n";
    d.addRandomMarks();
    std::vector<double> res = d.getPerformance();
    //for (int i=0;i<res.size();i++)
    //    std::cout<<res[i]<<" ";
    
    d.save("res.txt");
    return 0;
}