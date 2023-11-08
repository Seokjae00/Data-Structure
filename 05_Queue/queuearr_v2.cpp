#include "queuearr.h"
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber)
    : maxSize(maxNumber), front(-1), rear(-1)
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
    {
        cout << "Queue is Full, you can't Enqueue!" << endl;
    }
    else
    {
        rear = (++rear) % maxSize;
        dataItems[rear] = newDataItem;
        if (front == -1)
            front = 0;
    }
}

template < class DT >
DT Queue<DT>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty, you can't Dequeue" << endl;
        return NULL;
    }
    else
    {
        int currentFront = front;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (++front) % maxSize;
        return dataItems[currentFront];
    }
}

template < class DT >
void Queue<DT>::clear()
{
    front = -1;
    rear = -1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{
    return (front == -1);
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

    if (front == -1)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front = " << front << "  rear = " << rear << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (rear >= front)
            for (j = 0; j < maxSize; j++)
                if ((j >= front) && (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for (j = 0; j < maxSize; j++)
                if ((j >= front) || (j <= rear))
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
        cout << "Queue is Full, you can't Enqueue!" << endl;
    else
    {
        if (!isEmpty())
            front = (front - 1 + maxSize) % maxSize;
        else
        {
            front = 0;
            rear = 0;
        }

        dataItems[front] = newDataItem;
    }
}

template < class DT >
DT Queue<DT>::getRear()
{
    // In-lab 2
    if (isEmpty())
    {
        cout << "Queue is Empty, you can't Dequeue" << endl;
        return NULL;
    }
    else {
        int currentRear = rear;
        --rear;

        if (rear == front - 1)
            rear = front = -1;
        else if (rear < 0)
            rear = maxSize - 1;

        return dataItems[currentRear];
    }
}

template < class DT >
int Queue<DT>::getLength() const
{
    // In-lab 3
    if (isEmpty())
        return 0;
    else if (front > rear)
        return (maxSize - front) + (rear + 1);
    else
        return (rear - front) + 1;
}