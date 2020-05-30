#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Dean.h"

int main()
{
	Dean* dean = new Dean();

	dean->setMarks();
	dean->setHeads();
	dean->allocation();
	dean->transfer("18-PMI", "18-PI");
	dean->statistics();
	dean->savingData();
	delete dean;
	return 0;
}
