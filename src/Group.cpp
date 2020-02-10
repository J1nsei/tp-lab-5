#include "Group.h"

Group::Group(std::string title, std::string specialization)
{
    m_title = title;
    m_specialization = specialization;
    m_students = std::vector<Student *>();
    m_head = nullptr;
}

Group::Group(std::string title, std::string specialization, std::vector<Student *> students, Student *head)
    : Group(title, specialization)
{
    m_students = students;
    m_head = head;
}

void Group::AddStudent(Student *student)
{
    m_students.push_back(student);
}

void Group::RemoveStudent(Student *student)
{
    for (uint32_t i = 0; i < m_students.size(); i++)
        if (m_students[i] == student)
        {
            m_students.erase(m_students.begin() + i);
            break;
        }
}

Student *Group::GetStudentById(int32_t id)
{
    for (uint32_t i = 0; i < m_students.size(); i++)
        if (m_students[i]->GetId() == id)
            return m_students[i];
    return nullptr;
}

Student *Group::GetStudentByName(std::string firstName, std::string lastName)
{
    for (uint32_t i = 0; i < m_students.size(); i++)
        if (m_students[i]->GetFirstName() == firstName && m_students[i]->GetLastName() == lastName)
            return m_students[i];
    return nullptr;
}

float Group::CalculateAverageGrade()
{
    float sum = 0;
    for (uint32_t i = 0; i < m_students.size(); i++)
        sum += m_students[i]->CalculateAverageGrade();
    return sum / m_students.size();
}
