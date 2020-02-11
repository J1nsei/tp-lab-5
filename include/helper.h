//
// Created by fiskirton on 11.02.2020.
//

#ifndef TASK1_HELPER_H
#define TASK1_HELPER_H

#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <iostream>

std::vector<std::string> split(const std::string& s, char delimiter);
int getRandom(int min, int max);

template <typename T>
double mean(const std::vector<T> &values){

    T sum{0};

    for (auto& n : values)
        sum += n;

    return (double)sum / values.size();

}

#endif //TASK1_HELPER_H
