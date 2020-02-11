#include "Header.h"
#include "deanery.h"

int main()
{
	srand(time(NULL));
	Deanery D;
	cout << "\n Creating groups..." << endl;
	//D.createGroups();
	Group *G1 = new Group("group1");
	Group *G2 = new Group("group2");
	Group *G3 = new Group("group3");
	Student *s = new Student(1,"A A");
	s->addToGroup(G1);
	G1->addStudent(s);
	s = new Student(2,"B B");
	s->addToGroup(G1);
	G1->addStudent(s);
	s = new Student(3,"C C");
	s->addToGroup(G2);
	G2->addStudent(s);
	s = new Student(4, "F F");
	s->addToGroup(G3);
	G3->addStudent(s);
	s = new Student(5, " G G");
	s->addToGroup(G3);
	G3->addStudent(s);
	D.printGroups();
	cout << "choosing Heads.. \n";
	D.chooseHeadsRand();
	D.printHeads();

	cout << "\n Set Rand Marks..." << endl;
	D.setRandMarks();
	cout << "\nStatistic..." << endl;
	D.printStatistic();
	cout << "\n Detalied...\n" << endl;
	D.printStatisticDetailed();
	Group* gr = D.findGroup("group1");
	Student* st = gr->findLooser();
	cout << "\n\n st will delete " << st->getID() << endl;
	gr->studentExpell(st);
	cout << "\n\nNew List..\n" << endl;
	D.printGroups();
	cout << "\n\nTransfer..\n" << endl;
	st = D.findStudent(4);
	Group* gfrom = st->getGroup();
	Group* gTo = D.findGroup("group3");
	D.transferStudent(gfrom, gTo, st);
	cout << "\n\n New List.. \n\n";
	D.printGroups();
	//D.saveInform();
	cout << "final" << endl;
}