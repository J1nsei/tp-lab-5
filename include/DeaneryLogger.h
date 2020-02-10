#ifndef _DEANERYLOGGER_H_
#define _DEANERYLOGGER_H_

#include <iostream>
#include "Group.h"
#include "Student.h"

class DeaneryLogger
{
private:
    std::ostream *m_streamWriter;

public:
    DeaneryLogger(std::ostream *streamWriter);

    void WriteStudent(Student &student);
    void WriteGroup(Group &group);
};

#endif // _DEANERYLOGGER_H_
