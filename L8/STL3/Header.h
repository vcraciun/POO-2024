#pragma once
#include <map>
#include <string>
#include <Windows.h>
#include<fstream>
#include <iostream>
#include <queue>

using namespace std;
class FileProcessor
{
    int n;
    map < string, map<string, map<string, int>>> file;
    void scan(string name, int n);
    void procesare(string name, int n);
public:
    FileProcessor(string name, int n);
    void Print();
};