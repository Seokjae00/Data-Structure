#include "SortedType.h"


SortedType::SortedType()
    : length(0), cursor(-1)
{
}



void SortedType::insert(HouseType house)
{
    int location = 0;
    bool moreToSearch = (location < length);

    while (moreToSearch)
    {
        switch (house.CompareTo(houseList[location]))
        {
        case RelationType::LESS:
            moreToSearch = false;
            break;
        case RelationType::GREATER:
            location++;
            moreToSearch = (location < length);
            break;
        }
    }

    for (int i = length; i > location; i--)
        houseList[i] = houseList[i - 1];

    houseList[location] = house;
    length++;
}


void SortedType::remove(HouseType house)
{
    int location = 0;

    while (house.CompareTo(houseList[location]) != RelationType::EQUAL)
        location++;

    for (int i = location + 1; i < length; i++)
        houseList[i - 1] = houseList[i];

    length--;
}


void SortedType::retrive(HouseType& house, bool& found)
{
    int first = 0;
    int last = length - 1;
    int mid = 0;

    bool moreToSearch = (first <= last);

    while (moreToSearch && !found)
    {
        mid = (first + last) / 2;
        switch (house.CompareTo(houseList[mid]))
        {
        case RelationType::LESS:
            last = mid - 1;
            moreToSearch = (first <= last);
            break;
        case RelationType::GREATER:
            first = mid + 1;
            moreToSearch = (first <= last);
            break;
        case RelationType::EQUAL:
            found = true;
            house = houseList[mid];
            break;
        }
    }
}


bool SortedType::isFull() const
{
    return (length == MAXSIZE);
}


int SortedType::getLength() const
{
    return length;
}


void SortedType::clear()
{
    length = 0;
}


void SortedType::resetList()
{
    cursor = -1;
}


void SortedType::getNextHouse(HouseType& house)
{
    cursor++;
    house = houseList[cursor];
}
