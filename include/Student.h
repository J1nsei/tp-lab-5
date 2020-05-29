#ifndef STUDENT_H
#define STUDENT_H

class Group;
class Student {
private:
	std::string id;
	std::string fullName;
	Group* group;
	std::vector<int> marks;
	void addMark(int);
public:
	Student(std::string, std::string);
	
	std::string getName() const;
	std::string getId() const;
	Group* getGroup() const;
	std::vector<int> getMarks() const;
	double calculateAverage() const;
	void addToGroup(Group* newGroup);
	friend class Dean;
};

#endif