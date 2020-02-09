#pragma once
class Group;
class Student{
private:
    int id;
    std::string name;
    Group* group;
    std::vector<int> marks;
    void addMark(int);
public:
    Student(const int& _id, const std::string& _name, Group* _group);
    int gradePointAverage() const;
    int getId() const;
    std::string getName() const;
    Group* getGroup() const;
    std::vector<int> getMarks() const;
    friend class Dean;
    friend bool operator==(const Student & a, const Student & b);
};