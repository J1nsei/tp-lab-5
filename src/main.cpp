//
//  main.cpp
//  lab5
//
//  Created by Андрей Журавлев on 03.11.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include "Classes.hpp"



void printVec(std::vector<std::string> arr) {
    for (auto str : arr) {
        std::cout << str << std::endl;
    }
}

int main(int argc, const char * argv[]) {
	srand(int(time(NULL)));
	Deanery d("database.txt", "groups.txt");
	d.add_marks_for_groups();
	d.data_output();
//	d.head_choices();
	d.calculate_means();
	d.expell_students();
	std::cout << "=============================" << std::endl << std::endl;
	d.data_output();
	d.save_data("output.txt");
}
