#pragma once
#include <string>
#include <map>
#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>

using namespace std;

struct Fisier {
	string nume;
	map<string, int> freq;
};

class FileProcessor
{
	map<string, vector<Fisier>> fisier;
	int nr;
	void scanare_rec(string name);
	void parse(string filename);
public:
	FileProcessor(string name, int nr);
	void Print();
};