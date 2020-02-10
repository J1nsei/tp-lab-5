#include "DeaneryLogger.h"

DeaneryLogger::DeaneryLogger(std::ostream *streamWriter)
{
    this->m_streamWriter = streamWriter;
}

void DeaneryLogger::WriteStudent(Student &student)
{
    *m_streamWriter << std::string("Student Id: ") + std::to_string(student.GetId()) << std::endl;
    *m_streamWriter << std::string("First Name: ") + student.GetFirstName() << std::endl;
    *m_streamWriter << std::string("Last Name: ") + student.GetLastName() << std::endl;
    *m_streamWriter << std::string("Grades: ");
    for (uint32_t i = 0; i < student.GetGrades()->size(); i++)
        (i < student.GetGrades()->size() - 1)
        ? (*m_streamWriter << std::to_string((*student.GetGrades())[i]) + " ")
        : (*m_streamWriter << std::to_string((*student.GetGrades())[i]) << std::endl);
}

void DeaneryLogger::WriteGroup(Group &group)
{
    *m_streamWriter << std::string("Group Title: ") + group.GetTitle() << std::endl;
    *m_streamWriter << std::string("Group Specialization: ") + group.GetSpecialization() << std::endl;
    *m_streamWriter << std::string("Group Head: Id: ") + std::to_string(group.GetHead()->GetId())
        + ", First Name: " + group.GetHead()->GetFirstName()
        + ", Last Name: " + group.GetHead()->GetLastName() << std::endl;
    *m_streamWriter << std::string("Students: ");
    for (uint32_t i = 0; i < group.GetStudents()->size(); i++)
        (i < group.GetStudents()->size() - 1)
        ? (*m_streamWriter << std::to_string((*group.GetStudents())[i]->GetId()) + " ")
        : (*m_streamWriter << std::to_string((*group.GetStudents())[i]->GetId()) << std::endl);
}
