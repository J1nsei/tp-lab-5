//
// Created by Оксана on 15.01.2020.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

vector<string> split (const string &s, char diliniter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, diliniter))
        tokens.push_back(token);
    return tokens;
}

int main(){
    ifstream file("Names.txt");
    SetConsoleOutputCP (CP_UTF8);
    cout<<endl;
    system("chcp 65001");
    while (!file.eof()) {
        string buf;
        getline(file, buf, '\n');
        vector<string> data = split(buf, ' ');
        for (auto s : data) {
            cout << s << " ";
        }
        cout << "\n";
    }

}

