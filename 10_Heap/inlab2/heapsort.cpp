//--------------------------------------------------------------------
//
//  Laboratory B, In-lab Exercise 2                     heapsort.cpp
//
//   heapSort() function
//
//--------------------------------------------------------------------

template < class DT >
void moveDown ( DT dataItem [], int root, int size )

// Restores the binary tree that is rooted at root to a heap by moving
// dataItem[root] downward until the tree satisfies the heap property.
// Parameter size is the number of data items in the array.

{
    int largest = root; // Initialize largest as root
    int leftChild = 2 * root + 1; // left = 2*i + 1
    int rightChild = 2 * root + 2; // right = 2*i + 2

    // If left child is larger than root
    if (leftChild < size && dataItem[leftChild].pty() > dataItem[largest].pty())
        largest = leftChild;

    // If right child is larger than largest so far
    if (rightChild < size && dataItem[rightChild].pty()  > dataItem[largest].pty())
        largest = rightChild;

    // If largest is not root
    if (largest != root)
    {
        // swap(dataItem[root], dataItem[largest])
        DT tmp = dataItem[root];
        dataItem[root] = dataItem[largest];
        dataItem[largest] = tmp;

        // Recursively heapify the affected sub-tree
        moveDown(dataItem, largest, size);
    }
}

//--------------------------------------------------------------------

template < class DT >
void heapSort ( DT dataItems [], int size )

// Heap sort routine. Sorts the data items in the array in ascending
// order based on priority.

{
    DT temp;   // Temporary storage
    int j;     // Loop counter

    // Build successively larger heaps within the array until the
    // entire array is a heap.

    for ( j = (size-1)/2 ; j >= 0 ; j-- )
        moveDown(dataItems,j,size);

    // Swap the root data item from each successively smaller heap with
    // the last unsorted data item in the array. Restore the heap after
    // each exchange.

    for ( j = size-1 ; j > 0 ; j-- )
    {
        temp = dataItems[j];
        dataItems[j] = dataItems[0];
        dataItems[0] = temp;
        moveDown(dataItems,0,j);
    }
}

