#include "Deanery.h"
#include "DatabaseProvider.h"

int32_t main()
{
    DatabaseProvider databaseProvider("students.txt", "groups.txt");
    databaseProvider.LoadStudents();
    databaseProvider.LoadGroups();

    std::vector<Student *> *students = databaseProvider.GetStudents();
    std::vector<Group *> *groups = databaseProvider.GetGroups();

    DeaneryLogger logger(&std::cout);
    Deanery deanery(&logger, students, groups);
    deanery.LogStatistics();
    system("pause");

    databaseProvider.SaveStudents();
    databaseProvider.SaveGroups();
}
