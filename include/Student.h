#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <cstdint>
#include <string>
#include <vector>

class Student
{
private:
	int32_t m_id;
	std::string m_firstName;
	std::string m_lastName;
	std::vector<int8_t> m_grades;

public:
	Student(int32_t id, std::string firstName, std::string lastName);
	Student(int32_t id, std::string firstName, std::string lastName, std::vector<int8_t> grades);

	int32_t GetId() const { return m_id; }
	const std::vector<int8_t> *GetGrades() const { return &m_grades; }

	std::string GetFirstName() const { return m_firstName; }
	void SetFirstName(const std::string firstName) { m_firstName = firstName; }
	std::string GetLastName() const { return m_lastName; }
	void SetLastName(const std::string lastName) { m_lastName = lastName; }

	void AddGrade(int8_t mark);
	void RemoveGrade(int8_t mark);
	float CalculateAverageGrade();
};

#endif // _STUDENT_H_
