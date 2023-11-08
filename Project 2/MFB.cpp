#include "MFB.h"

Person::Person(const string& newName)
{
	name = newName;
}

Person::~Person()
{
	friends.clear();
}

MFB::~MFB()
{
	directory.clear();
	friendvalues.clear();
}

void MFB::createPerson(const string& newName)
{
	if (directory.count(newName))
		cout << "Same name person already exists." << endl;
	else
	{
		Person person(newName);
		directory.emplace(newName, person);
	}
}

void MFB::beFriend(const string& name1, const string& name2)
{
	if (name1 == name2)
	{
		cout << "The name is the same" << endl;
		return;
	}

	auto iterPerson1 = directory.find(name1);
	auto iterPerson2 = directory.find(name2);

	if (iterPerson1 == directory.end() || iterPerson2 == directory.end())
	{
		cout << "Couldn't find ";
		if (iterPerson1 == directory.end()) cout << name1;
		if (iterPerson2 == directory.end() && iterPerson1 == directory.end()) cout << " and ";
		if (iterPerson2 == directory.end()) cout << name2;
		cout << endl;
		return;
	}

	iterPerson1->second.friends.emplace_front(iterPerson2->second);
	iterPerson2->second.friends.emplace_front(iterPerson1->second);

	string twoPersonKey = name1 + name2;
	string twoPersonKey2 = name2 + name1;
	friendvalues.emplace(twoPersonKey, true);
	friendvalues.emplace(twoPersonKey2, true);
}

void MFB::unFriend(const string& name1, const string& name2)
{
	if (name1 == name2) 
	{
		cout << "The name is the same" << endl;
		return;
	}

	auto iterPerson1 = directory.find(name1);
	auto iterPerson2 = directory.find(name2);

	if (iterPerson1 == directory.end() || iterPerson2 == directory.end())
	{
		cout << "Couldn't find ";
		if (iterPerson1 == directory.end()) cout << name1;
		if (iterPerson2 == directory.end() && iterPerson1 == directory.end()) cout << " and ";
		if (iterPerson2 == directory.end()) cout << name2;
		cout << endl;
		return;
	}

	auto& friends1 = iterPerson1->second.friends;
	auto& friends2 = iterPerson2->second.friends;

	auto iterP1 = find_if(friends1.begin(), friends1.end(), [&](const auto& friend1) {
		return friend1.name == name2;
		});
	 
	auto iterP2 = find_if(friends2.begin(), friends2.end(), [&](const auto& friend2) {
		return friend2.name == name1;
		});

	friends1.erase(iterP1);
	friends2.erase(iterP2);

	string twoPersonKey = name1 + name2;
	friendvalues.erase(twoPersonKey);
}

void MFB::printFriend(const string& name1)
{
	auto iterPerson = directory.find(name1);
	
	if (iterPerson == directory.end())
		cout << "Couldn't find " << name1 << endl;
	else
	{
		const auto& friends = iterPerson->second.friends;
		for (auto it = friends.crbegin(); it != friends.crend(); ++it)
			cout << it->name << ' ';
		cout << endl;
	}
}

bool MFB::isFriend(const string& name1, const string& name2)
{
	if (name1 == name2)
	{
		cout << "The name is the same" << endl;
		return false;
	}
	
	auto iterPerson1 = directory.find(name1);
	auto iterPerson2 = directory.find(name2);

	if (iterPerson1 == directory.end() || iterPerson2 == directory.end())
	{
		cout << "Couldn't find ";
		if (iterPerson1 == directory.end()) cout << name1;
		if (iterPerson2 == directory.end() && iterPerson1 == directory.end()) cout << " and ";
		if (iterPerson2 == directory.end()) cout << name2;
		cout << endl;
		return false;
	}

	string twoPersonKey = name1 + name2;
	return friendvalues.count(twoPersonKey);
}