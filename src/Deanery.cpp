#include "Deanery.h"

Deanery::Deanery() 
{
    std::ofstream ofs("deanery.txt");
    ofs.close();
}

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
            Group* grp = new Group(s.substr(0, s.find(' ')), s.substr(s.find(' ')+1, s.length()));
            groups.push_back(grp);
        }
    }
    file.close();
}

std::vector<Group*> Deanery::getGroups() const
{
    return this->groups;
}

void Deanery::creationOfStudents(std::string fileName)
{
    std::ifstream file;
    file.open(fileName);
    if (file) 
    {
        std::string s;
        int id = 0;
        while (!file.eof())
        {
            
            getline(file, s);
            Student* stp = new Student(id, s);
            stp->enroll(groups[id%5]);
            groups[id%groups.size()]->addStudent(stp);
            id++;
        }
    } 
    file.close();
}

void Deanery::addRandomMarks()
{
    for (int i = 0; i < groups.size();i++)
    {
        std::vector<Student*> sds = groups[i]->getStudents();
        for (int j = 0; j < sds.size(); j++)
        {
            sds[j]->addMark(rand()%5+1);
            std::cout<<sds[j]->getID()<<" ";
            std::cout<<sds[j]->getFIO()<<" ";
            std::cout<<sds[j]->calcMean()<<"\n";
        }
    }
}

std::vector<double> Deanery::getPerformance()
{
   std::vector<double> res;
   for (int i=0;i<groups.size();i++)
   {
       res.push_back(groups[i]->calcMean());
   }
   return res;
}

void Deanery::transfer(Student* st, Group* gr1, Group* gr2)
{
    gr1->exclude(st->getID());
    st->enroll(gr2);
    gr2->addStudent(st);
}

void Deanery::excludeBadStudents()
{
    for (int i=0;i<groups.size();i++)
    {
        groups[i]->excludeBadStudents();
    }
}

void Deanery::save(std::string filename)
{
    std::ofstream out;          
    out.open(filename); 
    if (out.is_open())
    {
        for (int i=0;i<groups.size();i++)
        {
            out<<"Group: "<<groups[i]->getTitle()<<std::endl;
            for (int j=0;j<groups[i]->getStudents().size();j++)
            {
                out<<"ID: "<<groups[i]->getStudents()[j]->getID()<<std::endl;
                out<<"Student: "<<groups[i]->getStudents()[j]->getFIO()<<std::endl;
                out<<"Main Mark: "<<groups[i]->getStudents()[j]->calcMean()<<std::endl;
                out<<"\n";
            }
        }
    }
}

Deanery::~Deanery()
{
}