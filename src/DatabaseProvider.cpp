#include <fstream>
#include <sstream>
#include "DatabaseProvider.h"

std::vector<std::string> Split(std::string &str, char separator);
std::string Join(std::vector<std::string> substrings, char separator);

DatabaseProvider::DatabaseProvider(std::string studentRepositoryFileName, std::string groupRepositoryFileName)
{
    m_studentRepositoryFileName = studentRepositoryFileName;
    m_groupRepositoryFileName = groupRepositoryFileName;
    m_students = std::vector<Student *>();
    m_groups = std::vector<Group *>();
}

void DatabaseProvider::LoadStudents(std::istream &streamReader)
{
    m_students.clear();
    std::string str;
    std::getline(streamReader, str);
    while (str != "")
    {
        std::vector<std::string> substrings = Split(str, '\t');
        Student *student = new Student(std::stoi(substrings[0]), substrings[1], substrings[2]);
        if (substrings.size() > 3)
            for (uint32_t i = 3; i < substrings.size(); i++)
                student->AddGrade(std::stoi(substrings[i]));
        m_students.push_back(student);
        std::getline(streamReader, str);
    }
}

void DatabaseProvider::LoadStudents()
{
    std::ifstream streamReader(m_studentRepositoryFileName);
    LoadStudents(streamReader);
    streamReader.close();
}

void DatabaseProvider::LoadGroups(std::istream &streamReader)
{
    m_groups.clear();
    std::string str;
    std::getline(streamReader, str);
    while (str != "")
    {
        std::vector<std::string> substrings = Split(str, '\t');
        Group *group = new Group(substrings[0], substrings[1]);
        if (substrings.size() > 2)
        {
            int32_t studentId = std::stoi(substrings[2]);
            for (uint32_t i = 0; i < m_students.size(); i++)
                if (m_students[i]->GetId() == studentId)
                {
                    group->AddStudent(m_students[i]);
                    group->SetHead(m_students[i]);
                    break;
                }
            for (uint32_t i = 3; i < substrings.size(); i++)
            {
                int32_t studentId = std::stoi(substrings[i]);
                for (uint32_t j = 0; j < m_students.size(); j++)
                    if (m_students[j]->GetId() == studentId)
                    {
                        group->AddStudent(m_students[j]);
                        break;
                    }
            }
        }
        m_groups.push_back(group);
        std::getline(streamReader, str);
    }
}

void DatabaseProvider::LoadGroups()
{
    std::ifstream streamReader(m_groupRepositoryFileName);
    LoadGroups(streamReader);
    streamReader.close();
}

void DatabaseProvider::SaveStudents(std::ostream &streamWriter)
{
    for (uint32_t i = 0; i < m_students.size(); i++)
    {
        Student *student = m_students[i];
        std::vector<std::string> substrings;
        substrings.push_back(std::to_string(student->GetId()));
        substrings.push_back(student->GetFirstName());
        substrings.push_back(student->GetLastName());
        if (student->GetGrades()->size())
            for (uint32_t j = 0; j < student->GetGrades()->size(); j++)
                substrings.push_back(std::to_string(student->GetGrades()->at(j)));
        streamWriter << Join(substrings, '\t') << std::endl;
    }
}

void DatabaseProvider::SaveStudents()
{
    std::ofstream streamWriter(m_studentRepositoryFileName);
    SaveStudents(streamWriter);
    streamWriter.close();
}

void DatabaseProvider::SaveGroups(std::ostream &streamWriter)
{
    for (uint32_t i = 0; i < m_groups.size(); i++)
    {
        Group *group = m_groups[i];
        std::vector<std::string> substrings;
        substrings.push_back(group->GetTitle());
        substrings.push_back(group->GetSpecialization());
        if (group->GetStudents()->size() > 0)
        {
            int32_t headId = group->GetHead()->GetId();
            substrings.push_back(std::to_string(headId));

            for (uint32_t j = 0; j < group->GetStudents()->size(); j++)
                if (group->GetStudents()->at(j)->GetId() != headId)
                    substrings.push_back(std::to_string(group->GetStudents()->at(j)->GetId()));
        }
        streamWriter << Join(substrings, '\t') << std::endl;
    }
}

void DatabaseProvider::SaveGroups()
{
    std::ofstream streamWriter(m_groupRepositoryFileName);
    SaveGroups(streamWriter);
    streamWriter.close();
}

std::vector<std::string> Split(std::string &str, char separator)
{
    std::vector<std::string> substrings;
    std::istringstream splitStream(str);
    std::string newSubstring;
    while (std::getline(splitStream, newSubstring, separator))
        substrings.push_back(newSubstring);
    return substrings;
}

std::string Join(std::vector<std::string> substrings, char separator)
{
    std::string str;
    std::ostringstream joinStream;
    for (uint32_t i = 0; i < substrings.size(); i++)
        if (i < substrings.size() - 1)
            joinStream << substrings[i] << separator;
        else
            joinStream << substrings[i];
    return joinStream.str();
}
