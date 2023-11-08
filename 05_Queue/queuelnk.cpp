#include "queuelnk.h"
#include <iostream>

using namespace std;

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
    : dataItem(nodeData), next(nextPtr)
{
}

template <class DT>
Queue<DT>::Queue(int ignored)
    : front(nullptr), rear(nullptr)
{
}

template<class DT>
Queue<DT>::~Queue()
{
    clear();
}

template<class DT>
void Queue<DT>::enqueue(const DT& newDataItem)
{
	if (isFull())
		cout << "Queue is Full, you can't Enqueue!" << endl;
	else
	{
		QueueNode<DT>* newNode = new QueueNode<DT>(newDataItem, NULL);

		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}
}

template<class DT>
DT Queue<DT>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty, you can't Dequeue" << endl;
		return NULL;
	}
	else
	{
		QueueNode<DT>* temp = front;
		DT data = temp->dataItem;

		if (front == rear)
		{
			front = nullptr;
			rear = nullptr;
		}
		else
			front = front->next;

		delete temp;
		return data;
	}
}

template <class DT>
void Queue<DT>::clear()
{
	while (!isEmpty())
		dequeue();
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
	return (front == nullptr);
}

template<class DT>
bool Queue<DT>::isFull() const
{
	QueueNode<DT>* temp = new QueueNode<DT>(NULL, nullptr);

	if (temp == nullptr)
		return true;
	else
	{
		delete temp;
		return false;
	}
}

template<class DT>
void Queue<DT>::showStructure() const
{
    QueueNode<DT>* p;   // Iterates through the queue

    if (isEmpty())
        cout << "Empty queue" << endl;
    else
    {
        cout << "front ";
        for (p = front; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "rear" << endl;
    }
}