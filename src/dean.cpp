#include "dean.h"
#include "student.h"
#include <utility>

Deanery::Deanery(std::string file_students, std::string file_groups)
{
    FileStudents = std::move(file_students);
    FileGroups = std::move(file_groups);
}

void Deanery::addStudents()
{
    ifstream file(FileStudents);
    std::string studentInitials;

    int studentID = 1;

    while (getline(file, studentInitials))
    {
        students.push_back(new Student(studentID, studentInitials));
        studentID++;
    }

    file.close();
}

void Deanery::addGroups()
{
    ifstream file(FileGroups);
    std::string titleGroup;

    while (getline(file, titleGroup))
    {
        groups.push_back(new Group(titleGroup));
    }

    file.close();

    for (int i = 0; i < groups.size(); i++)
    {
        for (unsigned int j = i * (students.size() / groups.size()); j < (i + 1) * (students.size() / groups.size()); j++)
        {
            students[j]->addToGroup(groups[i]->title);
            groups[i]->addStudent(students[j]);
        }
    }
}

void Deanery::setMarks()
{
    int mark;

    for (auto & studentsAll : students)
    {
        mark = rand() % 10 + 1;
        studentsAll->setMarks(mark);
    }
}

void Deanery::getStatistics()
{
    for (auto & studentsAll : students)
    {
        studentsStatistics.emplace_back(studentsAll->getAverageMarks(), studentsAll->fio);
    }
    sort(studentsStatistics.begin(), studentsStatistics.end());

    for (auto & group : groups)
    {
        groupsStatistics.emplace_back(group->getAverageMark(), group->title);
    }
    sort(groupsStatistics.begin(), groupsStatistics.end());
}

void Deanery::changeGroup(Student *student, const std::string& groupTitle)
{
    for (auto & default_group : groups)
    {
        if (default_group->title == groupTitle)
        {
            std::string target_group = student->group;
            for (auto & group : groups)
            {
                if (group->title == target_group)
                {
                    group->deleteStudent(student->id);
                }
            }
            student->addToGroup(default_group->title);
            default_group->addStudent(student);
        }
    }
}

void Deanery::removeStudents()
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getAverageMarks() < 3)
        {
            std::string groupTitle = students[i]->group;
            for (auto & group : groups)
            {
                if (group->title == groupTitle)
                {
                    group->deleteStudent(students[i]->id);
                    students.erase(students.begin() + i);
                    i--;
                }
            }
        }
    }
}

void Deanery::updateData(const string& title_)
{
    ofstream file;
    file.open(title_);

    if (file.is_open())
    {
        file << "Students amount = " << students.size() << endl << endl;
        file << "Groups statistics:" << endl;
        file << endl;

        for (auto & group : groups)
        {
            file << "Group title - " << group->title << endl;
            file << "Group size = " << group->students.size() << endl;
            file << "Group average score = " << group->getAverageMark() << endl;
            file << "Group headman: " << group->head->fio << endl;
            file << endl;

            for (auto & student : group->students)
            {
                file << student->fio << " - ";
                for (int mark : student->marks)
                {
                    file << mark << " ";
                }
                file << "|avg: " << student->getAverageMarks() << "  ";
                file << endl;
            }
            file << endl;
        }

        file << "Students average marks:" << endl << endl;
        for (auto & i : studentsStatistics)
        {
            file << i.second << " - " << i.first << endl;
        }
        file << endl;

        file << "Groups average marks:" << endl << endl;
        for (auto & i : groupsStatistics)
        {
            file << i.second << " - " << i.first << endl;
        }
        file << endl;
    }
    file.close();
}

void Deanery::electHeadmans()
{
    for (auto & group : groups)
    {
        group->electHeadman();
    }
}

void Deanery::printConsole()
{
    cout << "Students amount = " << students.size() << endl;
    cout << endl;

    for (auto & group : groups)
    {
        cout << "Group title - " << group->title << endl;
        cout << "Group size = " << group->students.size() << endl;
        cout << "Group average score = " << group->getAverageMark() << endl;
        cout << "Group headman: " << group->head->fio << endl;
        cout << endl;

        for (auto & student : group->students)
        {
            cout << student->fio << " - ";
            for (int mark : student->marks)
            {
                cout << mark << " ";
            }
            cout << "|avg: " << student->getAverageMarks() << "  ";
            cout << endl;
        }
        cout << endl;
    }

    cout << "Students average marks:" << endl << endl;
    for (auto & i : studentsStatistics)
    {
        cout << i.second << " " << i.first << endl;
    }
    cout << endl;

    cout << "Groups average marks:" << endl << endl;
    for (auto & i : groupsStatistics)
    {
        cout << i.second << " " << i.first << endl;
    }
    cout << endl;
}

int Deanery::getStudentsAmount()
{
    return students.size();
}