//--------------------------------------------------------------------
//
//  Laboratory 13                                             heap.cpp
//
//  Actual implementation of class in the Heap ADT
//--------------------------------------------------------------------

#include "heap.h"

//--------------------------------------------------------------------


template<class DT>
Heap<DT>::Heap(int maxNumber)
    : size(0), maxSize(maxNumber)
{
    dataItems = new DT[maxSize];
}

template < class DT >
Heap<DT>::~Heap()
{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newDataItem)
{
    if (isFull())
        cout << "Heap is Full" << endl;
    else
    {
        //dataItems[size] = newDataItem;
        //size++;

        //int tmp = size - 1;
        //while (tmp != 0) {
        //    if (dataItems[tmp].pty() > dataItems[(tmp - 1) / 2].pty())
        //    {
        //        //swap(dataItems[tmp].pty(), dataItems[(tmp - 1)/ 2].pty())
        //        DT tmpHeap = dataItems[tmp];
        //        dataItems[tmp] = dataItems[(tmp - 1) / 2];
        //        dataItems[(tmp - 1) / 2] = tmpHeap;
        //        tmp = (tmp - 1) / 2;
        //    }
        //    else break;
        //}
        dataItems[size++] = newDataItem;
        int i = size - 1;

        while (i != 0 && dataItems[i].pty() > dataItems[(i - 1) / 2].pty()) //n이 0이 아니고, 부모노드보다 더 크면
        { 
            swap(dataItems[i], dataItems[(i - 1) / 2]); //swap
            i = (i - 1) / 2; //밑에서부터 root까지 올라간다
        }

    }
}

template < class DT >
DT Heap<DT>::removeMax()
{
    if (isEmpty())
    {
        cout << "Heap is Empty" << endl;

        DT tmpHeap;
        tmpHeap.setPty(-1);
        return tmpHeap;
    }
    //else
    //{
    //    DT tmpHeap = dataItems[0];
    //    size--;
    //    dataItems[0] = dataItems[size];
    //    int tmp = 0;

    //    while (tmp < size)
    //    {
    //        if (tmp * 2 + 2 < size)
    //        {
    //            // 두 개의 자식 노드 중 큰 게 어느 건지 확인
    //            if (dataItems[tmp * 2 + 1].pty() > dataItems[tmp * 2 + 2].pty())
    //            {
    //                // 루트 노드보다 자식 노드가 큰 지 확인
    //                if (dataItems[tmp * 2 + 1].pty() > dataItems[tmp].pty())
    //                {
    //                    DT tmpHeap = dataItems[tmp];
    //                    dataItems[tmp] = dataItems[tmp * 2 + 1];
    //                    dataItems[tmp * 2 + 1] = tmpHeap;
    //                    tmp = tmp * 2 + 1;
    //                }
    //                else break;
    //            }
    //            else
    //            {
    //                if (dataItems[tmp * 2 + 2].pty() > dataItems[tmp].pty())
    //                {
    //                    DT tmpHeap = dataItems[tmp];
    //                    dataItems[tmp] = dataItems[tmp * 2 + 2];
    //                    dataItems[tmp * 2 + 2] = tmpHeap;
    //                    tmp = tmp * 2 + 2;
    //                }
    //                else break;
    //            }
    //        }
    //        // 맨 마지막 오른쪽 자식 노드가 없을 때
    //        else if (tmp * 2 + 2 == size)
    //        {
    //            if (dataItems[tmp * 2 + 1].pty() > dataItems[tmp].pty())
    //            {
    //                DT tmpHeap = dataItems[tmp];
    //                dataItems[tmp] = dataItems[tmp * 2 + 1];
    //                dataItems[tmp * 2 + 1] = tmpHeap;
    //            }
    //            break;
    //        }
    //        else
    //            break;
    //    }
    //    return tmpHeap;
    //}
    else if (size == 1) 
    {
        DT tmp = dataItems[0];
        size--;
        return tmp;
    }
    else
    {
        DT data = dataItems[0];
        dataItems[0] = dataItems[size - 1];
        int i = 0;
        int lagerChildIndex;
        size--;

        while ((2 * i + 1) < size)
        {
            if (dataItems[2 * i + 1].pty() < dataItems[2 * i + 2].pty())
                lagerChildIndex = 2 * i + 2;
            else
                lagerChildIndex = 2 * i + 1;

            if (dataItems[i].pty() < dataItems[lagerChildIndex].pty())
            {
                swap(dataItems[i], dataItems[lagerChildIndex]);
                i = lagerChildIndex;
            }
            else
                break;
        }

        return data;
    }
}

template < class DT >
void Heap<DT>::clear()
{
	/*while (!isEmpty())
		removeMax();*/
    size = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const
{
    return (size == 0);
}

template < class DT >
bool Heap<DT>::isFull() const
{
    return (size == maxSize);
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::showStructure () const

// Outputs the priorities of the data in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << dataItems[j].pty() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::showSubtree ( int index, int level ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].pty();   // Output dataItems's pty
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::writeLevels() const
{
    if (isEmpty())
        return;

    int levelCount = 1;
    int printCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (printCount == levelCount)
        {
            cout << endl;
            printCount = 0;
            levelCount *= 2;
        }

        cout << dataItems[i].pty() << " ";
        printCount++;
    }

    cout << endl;
}