#include "gtest/gtest.h"
#include <locale.h>
#include "class.h"

TEST(laba5, test1) 
{
        setlocale(LC_ALL, "Russian");
	Student newcomer (91, "Богородицкая Екатерина Дмитриевна");
	newcomer.AddMark(1);
	newcomer.AddMark(2);
	newcomer.AddMark(3);
	double itog = newcomer.AvrMark();
	EXPECT_EQ(2.000000, itog);
}

TEST(laba5, test2) 
{
        setlocale(LC_ALL, "Russian");
	Group group("Группа");
	Student new1 (1, "Золотова Агния Агаповна");
	Student new2 (2, "Васнецова Марина Мечиславовна");
	Student new3 (3, "Калганова Татьяна Максимовна");
	group.JoinGroup(&new1);
	group.JoinGroup(&new2);
	group.JoinGroup(&new3);
	int place = group.Search(2);
        EXPECT_EQ(1, place);
}

TEST(laba5, test3) 
{
        setlocale(LC_ALL, "Russian");
	Group group("Группа");
	Student new1 (1, "Золотова Агния Агаповна");
	Student new2 (2, "Васнецова Марина Мечиславовна");
	new1.AddMark(8);
	new1.AddMark(5);
	new2.AddMark(4);
	new2.AddMark(3);
	group.JoinGroup(&new1);
	group.JoinGroup(&new2);
	double itog = group.AvrMark();
        EXPECT_EQ(5.000000, itog);
}

TEST(laba5, test4) 
{
	setlocale(LC_ALL, "Russian");
	Group group("Группа");
	Student new1(1, "Золотова Агния Агаповна");
	group.JoinGroup(&new1);
	group.ChooseLid();
        EXPECT_EQ("Золотова Агния Агаповна", group.GetLider());
}

TEST(laba5, test5) 
{
        setlocale(LC_ALL, "Russian");
	Group group("Группа");
	Student new1(1, "Золотова Агния Агаповна");
	Student new2(2, "Васнецова Марина Мечиславовна");
	Student new3(3, "Калганова Татьяна Максимовна");
	group.JoinGroup(&new1);
	group.JoinGroup(&new2);
	group.JoinGroup(&new3);
	group.ChooseLid();
	group.Delete(1);
	int place = group.Search(2);
        EXPECT_EQ(0, place);
}

TEST(laba5, test6) 
{
        setlocale(LC_ALL, "Russian");
	Deanery Main;
	std::vector<std::string> fio;
	fio.push_back("Золотова Агния Агаповна");
	fio.push_back("Васнецова Марина Мечиславовна");
	fio.push_back("Калганова Татьяна Максимовна");
	Main.CreateSt(fio);
	std::string fir = "Первая", sec = "Вторая", thi = "Третья";
	Main.CreateGr(fir, sec, thi);
        EXPECT_EQ("Вторая", Main.GroupName(1));
}
