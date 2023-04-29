
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void InsertionSort(int array[], int end)
{
    for (int i = 1; i < end; i++)
    {
        int key = array[i];
        int index = i;
        for (int j = i - 1; j >= 0 && key < array[j]; j--)
        {
            if (key <= array[j])
            {
                array[j + 1] = array[j];
                index = j;
            }
        }
        array[index] = key;
    }
}
void Merge(int array[], int start, int middle, int end)
{
    int lSize = middle - start + 1,
        rSize = end - middle;

    int L[lSize + 1], R[rSize + 1];

    //  Fill left array. // 0
    for (int i = 0; i < lSize; i++)
        L[i] = array[i + start];
    L[lSize] = 3;

    //  Fill right array. // 0
    for (int i = 0; i < rSize; i++)
        R[i] = array[i + middle + 1];
    R[rSize] = 3;

    int leftIndexTracer = 0, rightIndexTracer = 0;

    // Merging Loop
    while (start <= end)
    {
        if (L[leftIndexTracer] < R[rightIndexTracer])
            array[start++] = L[leftIndexTracer++];
        else if (L[leftIndexTracer] > R[rightIndexTracer])
            array[start++] = R[rightIndexTracer++];
        else
        {
            array[start++] = L[leftIndexTracer++];
            array[start++] = R[rightIndexTracer++];
        }
    }
}
void MergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        MergeSort(array, start, middle);
        MergeSort(array, middle + 1, end);
        Merge(array, start, middle, end);
    }
}
void SelectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_position])
            {
                min_position = j;
            }
        }
        if (min_position != i)
        {
            swap(&array[min_position], &array[i]);
        }
    }
}

void BubbleSort(int arr[], int end)
{
    for (int i = 0; i < sizeof(arr) - 1; i++)
    {
        for (int j = 0; j < sizeof(arr) - i - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void QuickSort(int array[], int low, int high)
{
    int L, R, pivot, temp;
    if (low < high)
    {
        pivot = low;
        L = low;
        R = high;
        while (L < R)
        {
            // loop on the left side
            while (array[L] <= array[pivot] && L < high)
            {
                L++;
            }
            // loop on the right side
            while (array[R] > array[pivot])
            {
                R--;
            }
            // swap the two pointers values cause they are swaped
            if (L < R)
            {
                temp = array[L];
                array[L] = array[R];
                array[R] = temp;
            }
        }
        // swap the value from the right pointer to pivot
        temp = array[pivot];
        array[pivot] = array[R];
        array[R] = temp;

        QuickSort(array, low, R - 1);
        QuickSort(array, R + 1, high);
    }
}
