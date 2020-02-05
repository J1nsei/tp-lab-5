#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "dean.h"

int main()
{
	Dean *dean = new Dean();

	dean->setMarks();
	//cout << dean->findGroup("18-ÏÌÈ")->averageMark() << endl;
	dean->setHeads();
	//cout << dean->findGroup("18-ÏÌÈ")->findStudent(3)->getName() << endl;

	dean->allocation();
	dean->transfer("18-ÏÌÈ", "18-ÏÈ");
	dean->statistics();
	dean->savingData();

	delete dean;
	return 0;
}