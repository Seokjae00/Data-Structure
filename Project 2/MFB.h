#pragma once
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Person
{
public:
	Person(const string& newName);
	~Person();

private:
	string name;
	list<Person> friends;

	friend class MFB;
};

class MFB
{
public:
	MFB() = default;
	~MFB();
	void createPerson(const string& newName);
	void beFriend(const string& name1, const string& name2);
	void unFriend(const string& name1, const string& name2);
	void printFriend(const string& name1);
	bool isFriend(const string& name1, const string& name2);

private:
	unordered_map<string, Person> directory;
	unordered_map<string, bool> friendvalues;
};