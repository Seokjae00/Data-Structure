#pragma once
#include "HouseType.h"

const int MAXSIZE = 20;

class SortedType
{
public:
	SortedType();
	void insert(HouseType house);
	void remove(HouseType house);
	void retrive(HouseType& house, bool& found);
	bool isFull() const;
	int getLength() const;
	void clear();
	void resetList();
	void getNextHouse(HouseType& house);

private:
	int length;
	int cursor;
	HouseType houseList[MAXSIZE];
};

