#ifndef _DEANERY_H_
#define _DEANERY_H_

#include <vector>
#include "DeaneryLogger.h"
#include "Group.h"
#include "Student.h"

class Deanery
{
private:
    DeaneryLogger *m_logger;
    std::vector<Student *> *m_students;
    std::vector<Group *> *m_groups;

public:
    Deanery(DeaneryLogger *logger, std::vector<Student *> *students, std::vector<Group *> *groups);

    const std::vector<Student *> *GetStudents() const { return m_students; }
    const std::vector<Group *> *GetGroups() const { return m_groups; }

    void LogStatistics();
    void CarryOutHeadElection();
    void MoveStudent(Student *student, Group &sourceGroup, Group &destinationGroup);
    void ExpellStudents(float gradeLowBound);
};

#endif // _DEANERY_H_
