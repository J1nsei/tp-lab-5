#include "Header.h"
#include "deanery.h"

int main()
{
	srand(time(NULL));
	Deanery D;
	cout << "\n Creating groups..." << endl;
	D.createGroups();
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