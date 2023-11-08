#include "listdbl.h"

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
    : dataItem(data), prior(priorPtr), next(nextPtr)
{
}

// Constructor
template < class DT >
List<DT>::List(int ignored)
    : head(nullptr), cursor(nullptr)
{
}

// Destructor
template < class DT >
List<DT>::~List()
{
    clear();
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
    if (isFull())
        cout << "Element cannot be inserted" << endl;
    else
    {
        ListNode<DT>* newNode;

        if (isEmpty())
        {
            newNode = new ListNode<DT>(newDataItem, nullptr, nullptr);
            head = newNode;
            newNode->prior = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode = new ListNode<DT>(newDataItem, cursor, cursor->next);
            cursor->next->prior = newNode;
            cursor->next = newNode;
        }

        cursor = newNode;
    }
}

// Remove data item
template < class DT >
void List<DT>::remove()
{
    if (isEmpty())
        cout << "Element cannot be deleted" << endl;
    else
    {
        ListNode<DT>* temp = cursor;

        if (temp == head)
        {
            if (cursor->next == head)
            {
                delete temp;
                head = cursor = nullptr;
            }
            else
            {
                head = cursor->next;
                gotoBeginning();
                cursor->prior = temp->prior;
                temp->prior->next = cursor;
                delete temp;
            }
        }
        else if (cursor->next == head)
        {
            head->prior = cursor->prior;
            cursor->prior->next = head;
            gotoBeginning();
            delete temp;
        }
        else
        {
            cursor->prior->next = cursor->next;
            cursor->next->prior = cursor->prior;
            gotoNext();
            delete temp;
        }
    }
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{
    if (isEmpty())
        cout << "Element cannot be replaced" << endl;
    else
        cursor->dataItem = newElement;
}

// Clear list
template < class DT >
void List<DT>::clear()
{
    ListNode<DT>* currentNode, * nextNode;

    if (head != nullptr)
    {
        currentNode = head;
        do
        {
            nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        } while (currentNode != head);

        head = nullptr;
        cursor = nullptr;
    }
}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
    return (head == nullptr);
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
    ListNode<DT>* temp = new ListNode<DT>(NULL, nullptr, nullptr);

    if (temp == nullptr)
        return true;
    else
    {
        delete temp;
        return false;
    }
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
    if (isEmpty())
        cout << "Cursor cannot be moved." << endl;
    else
        cursor = head;
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
    if (isEmpty())
        cout << "Cursor cannot be moved." << endl;
    else
        cursor = head->prior;
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
    if (!isEmpty() && (cursor->next != head))
    {
        cursor = cursor->next;
        return true;
    }
    else
        return false;
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{
    if (!isEmpty() && (cursor != head))
    {
        cursor = cursor->prior;
        return true;
    }
    else
        return false;
}


template < class DT >
DT List<DT>::getCursor() const
{
    if (isEmpty())
    {
        cout << "Unable to get the element." << endl;
        return NULL;
    }
    else
        return cursor->dataItem;
}


//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const
{
    ListNode<DT>* p;   // Iterates through the list

    if (head == nullptr)
        cout << "Empty list" << endl;
    else
    {
        p = head;
        do
        {
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
}


//-----------------------------------------------------------
// In-lab2 operation
template <class DT>
void List<DT>::reverse()
{
    if (isEmpty())
        cout << "Order of elements cannot be changed." << endl;
    else
    {
        if (head->next == head)
            return;

        ListNode<DT>* currentNode = head;
        ListNode<DT>* lastNode = head->prior;
        ListNode<DT>* nextNode;

        while (currentNode != lastNode)
        {
            nextNode = currentNode->next;
            currentNode->next = currentNode->prior;
            currentNode->prior = nextNode;
            currentNode = nextNode;
        }

        currentNode->next = currentNode->prior;
        currentNode->prior = head;
        //currentNode = head;
        head = lastNode;
        //lastNode = currentNode;
    }
}

// In-lab3 operation
template <class DT >
int List<DT>::getLength() const
{
    ListNode<DT>* tempNode = head;
    int count = 0;

    if (!isEmpty())
    {
        do
        {
            tempNode = tempNode->next;
            count++;
        } while (tempNode != head);
    }

    return count;
}

template <class DT>
int List<DT>::getPosition() const
{
    int count = 0;
    ListNode<DT>* tempNode = head;

    do
    {
        if (tempNode == cursor)
            break;
        tempNode = tempNode->next;
        count++;
    } while (tempNode != head);

    return count;
}