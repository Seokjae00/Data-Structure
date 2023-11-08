#include "HouseType.h"


HouseType::HouseType()
	: pyeong(0), roomCounter(0), price(0)
{
}


void HouseType::GetFromFile(ifstream& file)
{
	stringstream ss;
	string priceInfo = "";
	string roomInfo = "";
	string temp = "";

	getline(file, name);
	getline(file, address);
	getline(file, priceInfo);
	getline(file, roomInfo);
	file.ignore();

	ss.str(priceInfo);
	ss >> price;
	ss.clear();

	// ���ڸ� �����ϱ� ���� ����ǥ����
	regex pattern("\\d+");

	// ����ǥ���Ŀ� �´� ���ڸ� ã�Ƽ� ���
	sregex_iterator iter(roomInfo.begin(), roomInfo.end(), pattern);
	sregex_iterator end;

	while (iter != end) 
	{
		temp.append(iter->str());
		temp.append(" ");
		++iter;
	}

	ss.str(temp);
	ss >> pyeong >> roomCounter;
}


void HouseType::WriteToFile(ofstream& file) const
{
	file << name << endl;
	file << address << endl;
	file << price << " ��" << endl;
	file << pyeong << " ��, �� " << roomCounter;
}


void HouseType::GetFromUser()
{
	string roomInfo = "";
	cout << "Enter name; press return. ";
	cin >> name;
	cin.ignore();

	cout << "Enter address; press return. ";
	getline(cin, address);

	cout << "Enter price, square meter(pyung), number of bedrooms; press return. ";
	getline(cin, roomInfo);

	stringstream ss(roomInfo);
	ss >> price >> pyeong >> roomCounter;
}


void HouseType::GetNameFromUser()
{
	cout << "Enter name; press return. ";
	cin >> name;
}


void HouseType::PrintHouseToScreen() const
{
	cout << name << endl;
	cout << address << endl;
	cout << "����: " << price << " ��" << endl;
	cout << "����: " << pyeong << " ��, ��: " << roomCounter << endl;
}


RelationType HouseType::CompareTo(HouseType house) const
{
	if (name < house.name)
		return RelationType::LESS;
	else if (name > house.name)
		return RelationType::GREATER;
	else
		return RelationType::EQUAL;
}
