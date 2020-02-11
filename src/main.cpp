/*
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "class.h"

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream file("students.txt");
	std::vector<std::string> data;

	while (!file.eof())
	{
		std::string buf;
		getline(file, buf, '\n');
		data.push_back(buf);
		//std::cout << buf << '\n';
	}

	FILE *allstudents;
	allstudents = fopen("allstudents.txt", "w"); //çäåñü áóäåò îáíîâëåííûé ñïèñîê

	FILE *list;
	list = fopen("list.txt", "w"); //çäåñü áóäåò ñïèñîê ñî ñòàòèñòèêîé

	Deanery HSE;
	HSE.CreateSt(data);

	std::string first = "PMI1", second = "PMI2", third = "PMI3";
	HSE.CreateGr(first, second, third);

	HSE.AddMarks();
	HSE.AddMarks();
	HSE.AddMarks();

	HSE.ChooseLid();

	HSE.DeleteSt(18); // Óäàëèëè ñòàðîñòó, âìåñòî íåå âûáðàëè íîâóþ

	HSE.ChangeGr(70, second); //èç 3 ãðóïïû ïåðåâåëè âî 2

	HSE.about();
	HSE.Statictic(list);
	HSE.SaveData(allstudents);

}

*/
