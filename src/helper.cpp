//
// Created by fiskirton on 11.02.2020.
//

#include "helper.h"

std::vector<std::string> split(const std::string& s, char delimiter)
{

    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;

}

int getRandom(int min, int max){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);

}
