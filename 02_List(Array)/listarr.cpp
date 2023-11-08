//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

//--------------------------------------------------------------------

List::List(int maxNumber)
	: maxSize(maxNumber), size(0), cursor(-1)
// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	// pre-lab
	dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (isFull())
		cout << "Failed -- List is Full" << endl;
	else if (cursor == size - 1)
	{
		dataItems[++cursor] = newDataItem;
		size++;
	}
	else
	{
		for (int i = size; cursor < i; i--)
			dataItems[i] = dataItems[i - 1];

		dataItems[++cursor] = newDataItem;
		size++;
	}
}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (isEmpty())
		cout << "Failed -- List is empty" << endl;
	else if (size == 1)
		size--;
	else if (cursor == size - 1) 
	{
		cursor = 0;
		size--;
	}
	else
	{
		for (int i = cursor; i < size - 1; i++)
			dataItems[i] = dataItems[i + 1];

		size--;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (isEmpty())
		cout << "Failed -- List is empty" << endl;
	else
		dataItems[cursor] = newDataItem;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	size = 0; // 사이즈 초기화
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	// pre-lab
	return (size == 0);
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	// pre-lab
	return (size == maxSize);
}

//--------------------------------------------------------------------

void List::gotoBeginning()
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	if (isEmpty())
		cout << "Failed -- List is empty" << endl;
	else
		cursor = 0;
}

//--------------------------------------------------------------------

void List::gotoEnd()

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (isEmpty())
		cout << "Failed -- List is empty" << endl;
	else
		cursor = size - 1;
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (cursor != (size - 1))
	{
		cursor++;
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (cursor <= 0) // 커서가 리스트의 처음이 아니면 이전으로 이동
		return false;
	else
	{
		cursor--;
		return true;
	}
}

//--------------------------------------------------------------------

DataType List::getCursor() const
// Returns the item marked by the cursor.

{
	// pre-lab
	if (isEmpty())
	{
		cout << "Failed -- List is empty" << endl;
		return NULL;
	}
	else
		return dataItems[cursor]; // 커서가 가리키는 데이터 반환
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
    // pre-lab
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n)
{
	// in-lab 2
	if (n >= size)
		cout << "Failed -- " << n << " is greater than the index of the current list." << endl;
	else
	{
		DataType tmp = dataItems[cursor];
		if (cursor < n)
		{
			for (int i = cursor; i < n; i++)
				dataItems[i] = dataItems[i + 1];
		}
		else if (cursor > n)
		{
			for (int i = cursor; i > n; i--)
				dataItems[i] = dataItems[i - 1];
		}

		cursor = n;
		dataItems[n] = tmp;
	}
}
//
bool List::find(const DataType& searchDataItem)
{
	// in-lab 3
	if (isEmpty())
	{
		cout << "Failed -- List is empty" << endl;
		return false;
	}
	else
	{
		while (cursor < size) 
		{
			if (dataItems[cursor] == searchDataItem)
				return true;

			cursor++;
		}

		cursor--;
		return false;
	}
}