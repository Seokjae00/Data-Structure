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

	// 숫자만 추출하기 위한 정규표현식
	regex pattern("\\d+");

	// 정규표현식에 맞는 숫자를 찾아서 출력
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
	file << price << " 억" << endl;
	file << pyeong << " 평, 방 " << roomCounter;
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
	cout << "가격: " << price << " 억" << endl;
	cout << "평형: " << pyeong << " 평, 방: " << roomCounter << endl;
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
