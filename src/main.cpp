#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "student.h"
#include "group.h"
#include "dean.h"

using namespace std;

int main()
{
	system("chcp 65001");
	Dean* fimicn = new Dean();
	fimicn->addGroups("output.txt", "groups.txt");
	fimicn->chooseHeads();
	fimicn->set_random_marks(6);
	fimicn->getStatistics();
	cout << "=======================" << endl;
	fimicn->expelStudents();
	fimicn->getStatistics();
	cout << "=======================" << endl;

	getchar();

}