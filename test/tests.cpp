#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST(testStudent, init1) {
Student S1;
S1.create("Maxim",1);
EXPECT_EQ("Maxim", S1.getName());
}

TEST(testGroup, init2) {
Group G1;
G1.create("AMI-1", "Aplied math");
EXPECT_EQ("AMI-1", G1.getName());
}

TEST(testSwap, init3) {
    Deanery D1;
    std::vector<string> STDN{"Maxim","Jora"};
    std::vector<string> GRP{"AMI 2","EC 4"};
    D1.createGroups(GRP,"Aplied math and inf");
    D1.createStudents(STDN);
    D1.StudSwap("Jora","EC 4");
EXPECT_EQ(1, D1.GRsize(1));
}

TEST(testDel, init4) {
Group G1;
G1.create("AMI-1", "Aplied math");
Student S1;
S1.create("Maxim",1);
Student S2;
S2.create("Jora",1);
G1.addstud(&S1);
G1.addstud(&S2);
G1.delStud(1);
EXPECT_EQ(1, G1.getSize());
}

TEST(testMarks, init5) {
Student S1;
S1.create("Petya",11);
S1.addmark();
S1.addmark();
S1.addmark();
EXPECT_EQ(3, S1.getMarkssize());
}

TEST(testinGroup, init6) {
Student S3;
S3.create("Petya",11);
Group G3;
G3.create("AMI-1", "Aplied math");
S3.ingroup(&G3);
EXPECT_EQ(&G3, G3.getGroup());
}

TEST(testFindStudent, init7) {
Student S1;
S1.create("Petya",11);
Student S2;
S2.create("Kolya",12);
Student S3;
S3.create("Vika",13);
Group G1;
G1.create("AMI-1", "Aplied math");
Group G2;
G2.create("AMI-2", "Aplied math");
G1.addstud(&S1);
G1.addstud(&S3);
G2.addstud(&S2);
EXPECT_TRUE(G1.findS("Vika"));
}