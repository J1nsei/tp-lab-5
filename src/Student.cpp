#include "Student.h"

Student::Student(int32_t id, std::string firstName, std::string lastName)
{
    m_id = id;
    m_firstName = firstName;
    m_lastName = lastName;
    m_grades = std::vector<int8_t>();
}

Student::Student(int32_t id, std::string firstName, std::string lastName, std::vector<int8_t> grades)
    : Student(id, firstName, lastName)
{
    m_grades = grades;
}

void Student::AddGrade(int8_t mark)
{
    m_grades.push_back(mark);
}

void Student::RemoveGrade(int8_t mark)
{
    for (uint32_t i = 0; i < m_grades.size(); i++)
        if (m_grades[i] == mark)
        {
            m_grades.erase(m_grades.begin() + i);
            break;
        }
}

float Student::CalculateAverageGrade()
{
    float sum = 0;
    for (uint32_t i = 0; i < m_grades.size(); i++)
        sum += m_grades[i];
    return sum / m_grades.size();
}
