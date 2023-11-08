#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

enum class RelationType
{
	LESS, GREATER, EQUAL
};

class HouseType
{
public:
	HouseType();
	void GetFromFile(ifstream& file);
	void WriteToFile(ofstream& file) const;
	void GetFromUser();
	void GetNameFromUser();
	void PrintHouseToScreen() const;
	RelationType CompareTo(HouseType house) const;
	
private:
	string name;
	string address;
	int price;
	int pyeong;
	int roomCounter;
};

