#ifndef Student_H
#define Student_H
#include <vector>
#include <fstream>
#include <string>
//#include "Group.h"
//#include "Student.h"
class Group;
class Student {
private:
	int studentID;
	std::string fio;
	std::vector <int> marks;
	Group* group; // reference
public:
	// constructors ------------------------------------------------------------------
	/*Student() {
		fio = "NullStudent_" + getLastId();
		randomMarks();
		//group = nullptr;
		studentID = getLastId();
	}*/

	Student(std::string fullName) {
		fio = fullName;
		randomMarks();
		deleteMarks();
	}

	Student(int id, std::string lastname, std::string firstname, std::string middlename, std::string group) {
		fio = lastname + " " + firstname + " " + middlename;
		this->studentID = id;
		randomMarks();
	}

	//=========================================================================
	Student(int id, std::string fullName/*, Group* link*/) {
		fio = fullName;
		studentID = id;
		randomMarks();
		//group = link;
	}
	//=========================================================================

	/*Student(std::ifstream &fin) {
		char buf[50];
		fin.getline(buf, 50);
	}*/

	// methods -----------------------------------------------------------------------
	void addMark(int mark);	//done
	double averageMark();	//done
	void randomMarks();		//done
	//int getLastId();	//done
	int getId();	//done
	std::string getFIO();	//done
	void addToGroup(Group* _link);
	void setId(int id);
	
	void deleteMarks();
	void showMarks();		//done

	/*~Student() {

	}*/
};

#endif