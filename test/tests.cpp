#include "gtest/gtest.h"

TEST(lab5, task1){
	Student Eugene(0, "Eugene Melnikov");
	Eugene.addMark(10);
	Eugene.addMark(6);
	Eugene.addMark(5);
	double average = Eugene.averageMark();
	EXPECT_EQ(7, average);	
}

TEST(lab5, task2){
	Student stud1(0, "Alex");
	stud1.addMark(4);
	stud1.addMark(6);
	Student stud2(1, "Ivan");
	stud2.addMark(8);
	stud2.addMark(10);
	Student stud3(2, "Max");
	stud3.addMark(5);
	stud3.addMark(3);
	Group gr("pmi", "app. maths");
	gr.addStudent(&stud1);
	gr.addStudent(&stud2);
	gr.addStudent(&stud3);
	double average = gr.averageMarkGroup();
	EXPECT_EQ(6, average);	
}

TEST(lab5, task3){
	Student stud1(0, "Alex");;
	Student stud2(1, "Ivan");
	Student stud3(2, "Max");
	Group gr("pmi", "app. maths");
	gr.addStudent(&stud1);
	gr.addStudent(&stud2);
	gr.addStudent(&stud3);
	gr.chooseHead(&stud2);
	std::string headName = gr.getHead()->getFio();
	EXPECT_EQ("Ivan", headName);
	
}