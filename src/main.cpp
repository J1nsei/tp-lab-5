#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Dean.h"

int main() {
	Dean* dean = new Dean("../file/students.csv");
	Group* group = dean->findGroupByName("18PI-2");
	Group* group2 = dean->findGroupByName("18PMI-1");
	std::cout << group << std::endl;
	if (group != 0) {
		std::cout <<"Group name "<< group->getName() << std::endl;
		Student* Igor = group->findStudentById(35);
		Student* Sasha = group->findStudentByName("Конак Альбина Эрнестовна");
		Student* Miroslava = group->findStudentByName("Хейчеева Василиса Сидоровна");
		
		if (Igor != 0 && Sasha != 0) {
			for (int i = 0; i < 5; i++) {
				Igor->addMark(i);
				Sasha->addMark(i + 1);
			}
			std::cout << "Igor " << Igor << std::endl;
			std::cout << "Sasha " << Sasha << std::endl;
			std::cout << "Miroslava " << Miroslava << std::endl;
			if (Igor != 0) {
				//information about student
				std::cout << "FIO " << Igor->getFIO() << std::endl;
				std::cout << "Group " << Igor->getGroup()->getName() << std::endl;
				std::cout << "ID " << Igor->getID() << std::endl;
				//student and group statistics
				std::cout << "Average mark Igor " << Igor->averageMark() << std::endl;
				std::cout << "Average mark Sasha " << Sasha->averageMark() << std::endl;
				std::cout << "Group statistics " << group->averageMark() << std::endl;
				std::cout << dean->getGroupStatistics(group) << std::endl;
			}
			group->setHead(Miroslava);
			std::cout << "Head " << group->getHead() << std::endl;
			//delete student
			dean->expelStudent(Miroslava);			
			std::cout <<"Head "<< group->getHead() << std::endl;
			std::cout << "Miroslava " << Miroslava << std::endl;

			//transfer student
			std::cout << "Sasha group before transfer " << Sasha->getGroup()->getName() << std::endl;
			dean->studentTransfer(Sasha, group2);
			std::cout << "Sasha group after transfer " << Sasha->getGroup()->getName() << std::endl;

			//add student		
			dean->addNewStudent("Сидорова Мария Ивановна", group2);
			Student* newStudent = group2->findStudentByName("Сидорова Мария Ивановна");
			std::cout << "Group new sudent " << newStudent->getGroup()->getName() << std::endl;
			std::cout << "Name new student " << newStudent->getFIO() << std::endl;
			std::cout << "ID new student " << newStudent->getID() << std::endl;
			//dean->updateData();
			dean->outputData();
		}
	}
}
