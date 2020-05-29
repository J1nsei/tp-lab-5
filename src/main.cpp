#include "dean.h"

int main()
{
	srand(time(NULL));
	
	Dean *dean = new Dean();
	srand(time(NULL));
	dean->setMarks();
	dean->setHeads();
	dean->getStatistics();
	dean->transferStudents("Cameron Egbert", "18-AMI", "18-PI");
	
	dean->saveData();
	delete dean;
	/*
	Student s1("Khan Zamay", "ANTIHYPE");
	s1.setMarks();
	s1.printInformation();
	cout << s1.getStudentGroup() << endl;

	Student s2("BOOKER", "ANTIHYPE");
	s1.setGroup("PMI");
	s1.setMarks();
	s1.printInformation();
	
	Group gr1("18-ami");
	cout << gr1.getName() << endl;
	gr1.addStudent(&s1);
	gr1.appointHead();
	cout << gr1.getHeadName() << endl;
	gr1.setMarks();
	cout << gr1.countAverageMark() << endl;

	Group gr2("18-pmi");
	cout << gr2.getName() << endl;
	gr2.addStudent(&s2);
	gr2.appointHead();
	cout << gr2.getHeadName() << endl;
	gr2.setMarks();
	cout << gr2.countAverageMark() << endl;

	Dean d1("asdf");
	d1.addGroup(&gr1);
	d1.addGroup(&gr2);
	d1.setMarks();
	d1.setHeads();
	d1.getStatistics();
	cout << d1.getGroups()[0]->getHeadName() << endl;
	*/
	return 0;
}