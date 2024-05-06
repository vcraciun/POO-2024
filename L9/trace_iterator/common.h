#pragma once
#include <string>
#include <map>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Content
{
    unsigned int hash;
    string name;
    int count;
};

class TraceValidatorIterator
{
    map<string, map<int, Content>>::iterator it;
public:
    TraceValidatorIterator(map<string, map<int, Content>>::iterator it);
    map<string, map<int, Content>>::iterator operator->();
    pair<string, map<int, Content>> operator*();
    map<string, map<int, Content>>::iterator operator++();
    bool operator==(const TraceValidatorIterator& it);
    bool operator!=(const TraceValidatorIterator& it);
};

class TraceValidator
{
    map<string, map<int, Content>> data;
public:
    TraceValidator(string s);
    void Parse(string s);
    TraceValidatorIterator begin();
    TraceValidatorIterator end();
};
