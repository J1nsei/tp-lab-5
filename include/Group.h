#ifndef _GROUP_H_
#define _GROUP_H_

#include <string>
#include <vector>
#include "Student.h"

class Group
{
private:
	std::string m_title;
	std::string m_specialization;
	std::vector<Student *> m_students;
	Student *m_head;

public:
	Group(std::string title, std::string specialization);
	Group(std::string title, std::string specialization, std::vector<Student *> students, Student *head);

	const std::vector<Student *> *GetStudents() const { return &m_students; }

	std::string GetTitle() const { return m_title; }
	void SetTitle(std::string title) { m_title = title; }
	std::string GetSpecialization() const { return m_specialization; }
	void SetSpecialization(std::string specialization) { m_specialization = specialization; }
	Student *GetHead() const { return m_head; }
	void SetHead(Student *head) { m_head = head; }

	void AddStudent(Student *student);
	void RemoveStudent(Student *student);
	Student *GetStudentById(int32_t id);
	Student *GetStudentByName(std::string firstName, std::string lastName);
	float CalculateAverageGrade();
};

#endif // _GROUP_H_
