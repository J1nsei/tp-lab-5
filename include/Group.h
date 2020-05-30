#ifndef Group_H
#define Group_H

#include <vector>
//#include "Student.h"
#include "Student.h"
//class Student;

class Group {
private:
	int groupID = 0;
	std::string title;
	std::vector <Student*> students;
	Student* head;
public:
	// constructors ------------------------------------------------------------------

	/*Group() {

	}*/

	Group(std::string title) {
		this->title = title;
		students.resize(0);
		//resizeStudentsVector();
	}

	// methods -----------------------------------------------------------------------

	void addStudent(std::string fullName);	//done
	Student* headChoice(/*std::vector <Student> &students*/);	//done
	int getLastStudentId();	//done
	void resizeStudentsVector();	//done
	double averageGroupMark();	//done
	Student* searchStudent(int id);	//done
	Student* searchStudent(std::string fio);	//done
	//void excludeStudent(int id);	//done
	Group* getLink();	//done
	Student* dismissalStudent(int id);
	void addRandomMarks();
	void recieveStudent(Student* reciever);
	void studentDismissalProgressless();

	std::string getTitle();
	void statistics();

	void printTitle();	//done
	void printStudents();


	/*~Group() {

	}*/
};

#endif