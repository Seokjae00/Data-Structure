//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stacklnk.h"

//--------------------------------------------------------------------

template <class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
    : dataItem(nodeData), next(nextPtr)
{
}


//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int ignored)
    : top(nullptr)
{
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    clear();
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (isFull())
        cout << "Failed -- Full stack" << endl;
    else
        top = new StackNode<DT>(newDataItem, top);
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    if (isEmpty())
        return NULL;

    StackNode<DT>* tempPtr = top;
    DT tmp = top->dataItem;
    top = top->next;
    delete tempPtr;

    return tmp;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    StackNode<DT>* p = top, * nextP;
    while (p != nullptr)
    {
        nextP = p->next;
        delete p;
        p = nextP;
    }

    top = nullptr;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return (top == nullptr);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    StackNode<DT>* location = new StackNode<DT>(NULL, nullptr);
    if (location == nullptr)
        return true;
    else
    {
        delete location;
        return false;
    }
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Linked list implementation. Outputs the data items in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    StackNode<DT>* p;   // Iterates through the stack

    if (top == 0)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top ";
        for (p = top; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "bottom" << endl;
    }
}