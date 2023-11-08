//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber)
    : maxSize(maxNumber), top(-1)
{
    dataItems = new DT[maxSize];
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (isFull())
        cout << "Failed -- Full stack" << endl;
    else
        dataItems[++top] = newDataItem;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    if (isEmpty())
        return NULL;
    else
        return dataItems[top--];
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    while (!isEmpty())
        pop();
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return (top == -1);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    return (top == maxSize - 1);
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if (top == -1)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top = " << top << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j <= top; j++)
            cout << dataItems[j] << "\t";
        cout << endl;
    }
}