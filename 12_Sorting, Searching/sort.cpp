//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template < class DT >
void selectionSort(DT keyList[], int numKeys)

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
	int minIndex;
	DT temp;

	for (int i = 0; i < numKeys - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < numKeys; j++)
			if (keyList[minIndex] > keyList[j])
				minIndex = j;

		if (minIndex != i)
		{
			temp = keyList[minIndex];
			keyList[minIndex] = keyList[i];
			keyList[i] = temp;
		}
	}
}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys)

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys,
    int left, int right)

    // Recursive partner of the quickSort routine. Partitions the array
    // entries between left and right into two subarrays. One subarray
    // contains the keys that are less than or equal to splitValue, and
    // the other contains the keys that are greater than splitValue.
    // Recursively sorts each of these subarrays.

{
    DT splitVal = keyList[left];
    int i = left;
    int j = right;
    DT temp;

    do
    {
        while (keyList[i] < splitVal)   i++;

        while (keyList[j] > splitVal)   j--;

        if (i <= j)
        {
            temp = keyList[i];
            keyList[i] = keyList[j];
            keyList[j] = temp;
            i++; j--;
        }

    } while (i <= j);

    if (left < j)
        quickPartition(keyList, numKeys, left, j);

    if (i < right)
        quickPartition(keyList, numKeys, i, right);
}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys)
{
    DT temp;

    for (int i = 0; i < numKeys - 1; ++i)
    {
        for (int j = i + 1; j < numKeys; ++j)
        {
            if (keyList[j] < keyList[i])
            {
                temp = keyList[i];
                keyList[i] = keyList[j];
                keyList[j] = temp;
            }
        }
    }
}
