#include "Deanery.h"

Deanery::Deanery(DeaneryLogger *logger, std::vector<Student *> *students, std::vector<Group *> *groups)
{
    this->m_logger = logger;
    this->m_students = students;
    this->m_groups = groups;
}

void Deanery::LogStatistics()
{
    for (uint32_t i = 0; i < m_students->size(); i++)
        m_logger->WriteStudent(*(*m_students)[i]);
    for (uint32_t i = 0; i < m_groups->size(); i++)
        m_logger->WriteGroup(*(*m_groups)[i]);
}

void Deanery::CarryOutHeadElection()
{
    for (uint32_t i = 0; i < m_groups->size(); i++)
    {
        float maxGrade = 0;
        uint32_t index = 0;
        for (uint32_t j = 0; j < (*m_groups)[i]->GetStudents()->size(); j++)
        {
            if ((*(*m_groups)[i]->GetStudents())[j]->CalculateAverageGrade() > maxGrade)
            {
                maxGrade = (*(*m_groups)[i]->GetStudents())[j]->CalculateAverageGrade();
                index = j;
            }
            (*m_groups)[i]->SetHead((*(*m_groups)[i]->GetStudents())[index]);
        }
    }
}

void Deanery::MoveStudent(Student *student, Group &sourceGroup, Group &destinationGroup)
{
    sourceGroup.RemoveStudent(student);
    destinationGroup.AddStudent(student);

    if (sourceGroup.GetHead() == student && sourceGroup.GetStudents()->size() > 0)
    {
        float maxGrade = 0;
        uint32_t index = 0;
        for (uint32_t j = 0; j < sourceGroup.GetStudents()->size(); j++)
        {
            if ((*sourceGroup.GetStudents())[j]->CalculateAverageGrade() > maxGrade)
            {
                maxGrade = (*sourceGroup.GetStudents())[j]->CalculateAverageGrade();
                index = j;
            }
            sourceGroup.SetHead((*sourceGroup.GetStudents())[index]);
        }
    }
}

void Deanery::ExpellStudents(float gradeLowBound)
{
    for (uint32_t i = 0; i < m_groups->size(); i++)
    {
        for (uint32_t j = 0; j < (*m_groups)[i]->GetStudents()->size(); j++)
        {
            if ((*(*m_groups)[i]->GetStudents())[j]->CalculateAverageGrade() < gradeLowBound)
            {
                Student *studentToExpell = (*(*m_groups)[i]->GetStudents())[j];
                for (uint32_t k = 0; k < m_students->size(); k++)
                {
                    if ((*m_students)[k] == studentToExpell)
                    {
                        m_students->erase(m_students->begin() + k);
                        break;
                    }
                }
                (*m_groups)[i]->RemoveStudent(studentToExpell);
                if ((*m_groups)[i]->GetHead() == studentToExpell && (*m_groups)[i]->GetStudents()->size() > 0)
                {
                    float maxGrade = 0;
                    uint32_t index = 0;
                    for (uint32_t j = 0; j < (*m_groups)[i]->GetStudents()->size(); j++)
                    {
                        if ((*(*m_groups)[i]->GetStudents())[j]->CalculateAverageGrade() > maxGrade)
                        {
                            maxGrade = (*(*m_groups)[i]->GetStudents())[j]->CalculateAverageGrade();
                            index = j;
                        }
                        (*m_groups)[i]->SetHead((*(*m_groups)[i]->GetStudents())[index]);
                    }
                }
                delete studentToExpell;
                j--;
            }
        }
    }
}
