#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include "Deanery.h"
using namespace std;

int main(){
	srand(time(0));
	setlocale(LC_ALL, "rus");
	Deanery test;
	test.CreateGroups("groups.txt");
	test.AddRandMarks(5);
	test.ChooseHead();
	test.PrintStat();
	test.Transf("Шабалин Варфоломей Григориевич", "FM", "L");
	test.PrintStat();
	test.Expulsion(3.5);
	test.PrintStat();
	test.SaveData();
	test.PrintData();
	return 0;
}
