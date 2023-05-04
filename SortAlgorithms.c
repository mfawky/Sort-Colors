void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void InsertionSort(int nums[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = nums[i];
        int index = i;
        for (int j = i - 1; j >= 0 && key < nums[j]; j--)
        {
            if (key <= nums[j])
            {
                nums[j + 1] = nums[j];
                index = j;
            }
        }
        nums[index] = key;
    }
}
void Merge(int nums[], int start, int middle, int end)
{
    int lSize = middle - start + 1,
        rSize = end - middle;

    int L[lSize + 1], R[rSize + 1];

    //  Fill left array. // 0
    for (int i = 0; i < lSize; i++)
        L[i] = nums[i + start];
    L[lSize] = 3;

    //  Fill right array. // 0
    for (int i = 0; i < rSize; i++)
        R[i] = nums[i + middle + 1];
    R[rSize] = 3;

    int leftIndexTracer = 0, rightIndexTracer = 0;

    // Merging Loop
    while (start <= end)
    {
        if (L[leftIndexTracer] < R[rightIndexTracer])
            nums[start++] = L[leftIndexTracer++];
        else if (L[leftIndexTracer] > R[rightIndexTracer])
            nums[start++] = R[rightIndexTracer++];
        else
        {
            nums[start++] = L[leftIndexTracer++];
            nums[start++] = R[rightIndexTracer++];
        }
    }
}
void MergeSort(int nums[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        MergeSort(nums, start, middle);
        MergeSort(nums, middle + 1, end);
        Merge(nums, start, middle, end);
    }
}
void SelectionSort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[min_position])
            {
                min_position = j;
            }
        }
        if (min_position != i)
        {
            swap(&nums[min_position], &nums[i]);
        }
    }
}

void BubbleSort(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
}

void QuickSort(int nums[], int low, int high)
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
            while (nums[L] <= nums[pivot] && L < high)
            {
                L++;
            }
            // loop on the right side
            while (nums[R] > nums[pivot])
            {
                R--;
            }
            // swap the two pointers values cause they are swaped
            if (L < R)
            {
                temp = nums[L];
                nums[L] = nums[R];
                nums[R] = temp;
            }
        }
        // swap the value from the right pointer to pivot
        temp = nums[pivot];
        nums[pivot] = nums[R];
        nums[R] = temp;

        QuickSort(nums, low, R - 1);
        QuickSort(nums, R + 1, high);
    }
}
