#include "queuearr.h"
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber)
    : maxSize(maxNumber + 1), front(maxSize - 1), rear(maxSize - 1)
{
    dataItems = new DT[maxSize];
}

template < class DT >
Queue<DT>::~Queue()
{
    delete[] dataItems;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newDataItem)
{
    if (isFull())
        cout << "Failed-- Queue is Full!" << endl;
    else
    {
        rear = (++rear) % maxSize;
        dataItems[rear] = newDataItem;
    }
}

template < class DT >
DT Queue<DT>::dequeue()
{
    if (isEmpty())
    {
        cout << "Failed-- Queue is Empty" << endl;
        return NULL;
    }
    else
    {
        front = (++front) % maxSize;
        return dataItems[front];
    }
}

template < class DT >
void Queue<DT>::clear()
{
    front = maxSize - 1;
    rear = maxSize - 1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{
    return (rear == front);
}

template < class DT >
bool Queue<DT>::isFull() const
{
    return ((rear + 1) % maxSize == front);
}

template < class DT >
void Queue<DT>::showStructure() const
{
    int j;   // Loop counter

    if (isEmpty())
        cout << "Empty queue" << endl;
    else
    {
        cout << "front = " << front << "  rear = " << rear << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (rear > front)
            for (j = 0; j < maxSize; j++)
                if ((j > front) && (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for (j = 0; j < maxSize; j++)
                if ((j > front) || (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }

}

// In-lab operations
template < class DT >
void Queue<DT>::putFront(const DT& newDataItem)
{
    // In-lab 2
    if (isFull())
        cout << "Failed-- Queue is Full!" << endl;
    else
    {
        dataItems[front] = newDataItem;
        front = (--front) % maxSize;
        //front = (front - 1 + maxSize) % maxSize;
    }
}

template < class DT >
DT Queue<DT>::getRear()
{
    // In-lab 2
    if (isEmpty())
    {
        cout << "Failed-- Queue is Empty!" << endl;
        return NULL;
    }
    else
    {
        int curRear = rear;
        rear = (rear - 1 + maxSize) % maxSize;
        return dataItems[curRear];
    }
}

template < class DT >
int Queue<DT>::getLength() const
{
    // In-lab 3
    if (isEmpty())
        return 0;
    else if (front < rear)
        return rear - front;
    else if (rear < front)
        return maxSize - (front - rear);
}