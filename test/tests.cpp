#include "gtest/gtest.h"
#include "Deanery.h"

#include <fstream>
#include <string>

using namespace std;


class DeaneryInitSuit : public ::testing::Test {

private:

    string students_file_path = "../test/data/students.csv";
    string groups_file_path = "../test/data/groups.csv";
    
protected:
    void TearDown() override {

        delete deanery;
    }

    void SetUp() override {
        deanery = new Deanery(students_file_path, groups_file_path);
    }
    
    Deanery * deanery{};
    
};


TEST_F(DeaneryInitSuit, deanery_init_test) {
    ASSERT_NE(deanery->getGroups().size(), 0);
}


TEST_F(DeaneryInitSuit, deanery_headmen_init_test) {

    for (auto group: deanery->getGroups()){
        ASSERT_EQ(&group->getHead(), group->getStudents()[0]);
    }

}

TEST_F(DeaneryInitSuit, add_random_marks_check_vector_length) {

    deanery->addRandomMarks();

    for (auto group: deanery->getGroups()){
        for (auto student: group->getStudents()){
            EXPECT_NE(student->getMarks().size(), 0);
        }
    }

}

TEST_F(DeaneryInitSuit, add_random_marks_check_students_mean_mark) {

    deanery->addRandomMarks();

    for (auto group: deanery->getGroups()){
        for (auto student: group->getStudents()){
            EXPECT_NE(student->getMeanMark(), 0);
        }
    }

}

TEST_F(DeaneryInitSuit, add_random_marks_check_group_mean_mark){

    deanery->addRandomMarks();

    for (auto group: deanery->getGroups()){
        EXPECT_NE(group->getGroupMeanMark(), 0);
    }

}

class DeaneryDataChangeSuit : public ::testing::Test {

private:

    const string students_file_path = "../test/data/students.csv";
    const string groups_file_path = "../test/data/groups.csv";
    const string students_file_path_backup = "../backup/students.csv";
    const string groups_file_path_backup = "../backup/groups.csv";

protected:
    void TearDown() override {

        string line;

        ofstream students_out(students_file_path);
        ifstream students_in(students_file_path_backup);

        if (students_out.is_open() && students_in.is_open()) {
            while (getline(students_in, line)){
                students_out << line << endl;
            }
        }

        delete deanery;
    }

    void SetUp() override {
        deanery = new Deanery(students_file_path, groups_file_path);
        deanery->addRandomMarks();
    }

    Deanery * deanery{};

};

TEST_F(DeaneryDataChangeSuit, exclude_student_check_students_length_decrease) {

    int stdnts;

    stdnts = deanery->getGroups().back()->getStudents().size();

    deanery->excludeStudent(25);
    EXPECT_NE(deanery->getGroups().back()->getStudents().size(), stdnts);

}

TEST_F(DeaneryDataChangeSuit, exclude_student_check_headman_change) {

    string headman_fio = deanery->getGroups()[0]->getHead().getFio();
    deanery->excludeStudent(1);
    EXPECT_NE(deanery->getGroups()[0]->getHead().getFio(), headman_fio);

}


TEST_F(DeaneryDataChangeSuit, exclude_student_check_group_mean_mark_change) {

    double mean_mark;
    int id;

    for (auto group: deanery->getGroups()){

        mean_mark = group->getGroupMeanMark();
        id = group->getStudents()[0]->getId();
        deanery->excludeStudent(id);
        EXPECT_NE(group->getGroupMeanMark(), mean_mark);

    }

}

TEST_F(DeaneryDataChangeSuit, transfer_check_students_length_decrease) {


    int students_last;
    int students_first;

    students_last = deanery->getGroups().back()->getStudents().size();
    students_first = deanery->getGroups()[0]->getStudents().size();

    deanery->transferStudent(25, "18ПИ-2");

    EXPECT_NE(deanery->getGroups().back()->getStudents().size(), students_last);
    EXPECT_NE(deanery->getGroups()[0]->getStudents().size(), students_first);

}


TEST_F(DeaneryDataChangeSuit, transfer_check_student_group_change) {

    string group_title = deanery->getGroups()[0]->getTitle();

    Student & student = *deanery->getGroups()[0]->getStudents()[0];
    deanery->transferStudent(1, "18БИ-1");
    EXPECT_NE(student.getGroup().getTitle(), group_title);

}

TEST_F(DeaneryDataChangeSuit, transfer_check_group_mean_mark_change) {

    double group_mean_mark_first = deanery->getGroups()[0]->getGroupMeanMark();
    double group_mean_mark_last = deanery->getGroups().back()->getGroupMeanMark();

    deanery->transferStudent(1, "18БИ-1");

    EXPECT_NE(deanery->getGroups()[0]->getGroupMeanMark(), group_mean_mark_first);
    EXPECT_NE(deanery->getGroups().back()->getGroupMeanMark(), group_mean_mark_last);

}

