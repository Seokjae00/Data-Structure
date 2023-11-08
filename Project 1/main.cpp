#include "SortedType.h"

using namespace std;

bool g_Flag = true;

enum class CommandType
{
	ADD, DELETE, PRINTONE, PRINTALL, QUIT
};

void FileToList(SortedType& houseList, ifstream& masterIn)
{
	HouseType house;
	masterIn.open("house.mf");

	if (masterIn.fail()) {
		cout << "Cannot Open File!" << endl;
		exit(1);
	}

	houseList.clear();
	while (masterIn)
	{
		house.GetFromFile(masterIn);
		houseList.insert(house);
	}

	masterIn.close();
}

void ListToFile(SortedType houseList, ofstream& masterOut)
{
	masterOut.open("house.mf");
	HouseType house;
	int length = houseList.getLength();
	for (int i = 1; i <= length; i++)
	{
		houseList.getNextHouse(house);
		house.WriteToFile(masterOut);

		if (i != length)
			masterOut << endl << endl;
	}
	masterOut.close();
}

void AddHouse(SortedType& houseList)
{
	bool found = false;
	HouseType house;
	house.GetFromUser();
	houseList.retrive(house, found);
	if (!found)
	{
		houseList.insert(house);
		cout << "Operation completed." << endl;
	}
	else
		cout << "Duplicate name; operation aborted" << endl;
}

void DeleteHouse(SortedType& houseList)
{
	HouseType house;
	bool found = false;
	house.GetNameFromUser();
	houseList.retrive(house, found);
	if (found)
	{
		houseList.remove(house);
		cout << "Operation completed." << endl;
	}
	else
		cout << "Person not in list." << endl;
}

void PrintHouse(SortedType houseList)
{
	bool found = false;
	HouseType house;
	house.GetNameFromUser();
	houseList.retrive(house, found);
	if (found)
		house.PrintHouseToScreen();
	else
		cout << "Owner not in list." << endl;
}

void PrintAllHouse(SortedType houseList)
{
	HouseType house;
	int length = houseList.getLength();
	houseList.resetList();
	for (int i = 1; i <= length; i++)
	{
		houseList.getNextHouse(house);
		house.PrintHouseToScreen();

		if(i != length)
			cout << endl;
	}
}

void GetCommand(CommandType& command)
{
	if (g_Flag)
	{
		cout << "Operations are listed below." << endl;
		cout << "Enter the appropriate uppercase letter and";
		cout << "Press return." << endl;
		cout << "A: Add a house to the list of house." << endl;
		cout << "D: Delete a specific owner's house." << endl;
		cout << "P: Print the information about an owner¡¯s house." << endl;
		cout << "L: Print all the names on the screen." << endl;
		cout << "Q: Quit processing." << endl << endl;
		g_Flag = false;
	}

	char ch = 0;
	cin >> ch;

	bool ok = false;
	while (!ok)
	{
		ok = true;
		switch (ch)
		{
		case 'A':
			command = CommandType::ADD;
			break;
		case 'D':
			command = CommandType::DELETE;
			break;
		case 'P':
			command = CommandType::PRINTONE;
			break;
		case 'L':
			command = CommandType::PRINTALL;
			break;
		case 'Q':
			command = CommandType::QUIT;
			break;
		default:
			cout << "Letter entered is not one of the specified uppercase commands. "
				<< "Reenter and press return." << endl;
			
			cin >> ch;
			ok = false;
 			break;
		}
	}
}

int main(void)
{
	ifstream masterIn;
	ofstream masterOut;
	CommandType command;
	SortedType houseList;

	FileToList(houseList, masterIn);
	GetCommand(command);

	while (command != CommandType::QUIT)
	{
		switch (command)
		{
		case CommandType::ADD: 
			AddHouse(houseList);
			cout << endl;
			break;
		case CommandType::DELETE: 
			DeleteHouse(houseList);
			cout << endl;
			break;
		case CommandType::PRINTONE: 
			PrintHouse(houseList);
			cout << endl;
			break;
		case CommandType::PRINTALL:
			PrintAllHouse(houseList);
			cout << endl;
			break;
		}

		GetCommand(command);
	}

	ListToFile(houseList, masterOut);
	return 0;
}