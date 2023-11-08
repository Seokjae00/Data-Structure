//--------------------------------------------------------------------
//
//  Laboratory 5                                          stackarr.h
//
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include <iostream>

using namespace std;

const int defMaxStackSize = 10;   // Default maximum stack size

template < class DT >
class Stack
{
public:

	// Constructor
	Stack(int maxNumber = defMaxStackSize);

	// Destructor
	~Stack();

	// Stack manipulation operations
	void push(const DT& newDataItem);    // Push data item
	DT pop();                             // Pop data item
	void clear();                         // Clear stack

	// Stack status operations
	bool isEmpty() const;                    // Stack is empty
	bool isFull() const;                     // Stack is full

	// Output the stack structure -- used in testing/debugging
	void showStructure() const;

private:

	// Data members
	int maxSize,   // Maximum number of data items in the stack
		top;       // Index of the top data item
	DT* dataItems;   // Array containing the stack data items
};