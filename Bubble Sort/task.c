#include <stdio.h>
#include <stdlib.h>

//  Utilities Section
//=======================================================================================
int ValidateArray(int array[], int size)
{
    int i = 0;

    if (sizeof(array) == 1 && (array[i] >= 0 || array[i] <= 2))
    {
        return 1;
    }

    for(; i < size; i++)
    {
        if (array[i] > 2 || array[i] < 0)
        {
            i = 0;
            break;
        }
    }
    return i;
}
void GenerateFilledArray(int array[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", (array + i));
}

void SwapArrayElements(int array[], int i, int j)
{
    int swapper = array[i];
    array[i] = array[j];
    array[j] = swapper;
}

void PrintAlgorithmsTitles()
{
    puts("\nInsertion Sort    \t=> 1");
    puts("Merge Sort        \t=> 2");
    puts("Selection Sort    \t=> 3");
    puts("Bubble Sort       \t=> 4");
    puts("Quick Sort        \t=> 5\n");
}

void PrintSortedArray(int array[], int size)
{
    printf("\nResult : [");
    for (int i = 0; i < size - 1; i++)
        printf("%d, ", array[i]);
    printf("%d]\n\n", array[size - 1]);
}

void PickAlgorithm(int array[], int size)
{
    char algorithmPicker;
    do
    {
        scanf(" %c", &algorithmPicker);
        switch(algorithmPicker)
        {
            case '1':
                puts("You Picked Insertion Sort Algorithm");
                InsertionSort(array, size);
                break;
            case '2':
                puts("You Picked Merge Sort Algorithm");
                MergeSort(array, 0, size - 1);
                break;
            case '3':
                puts("You Picked Selection Sort Algorithm");
                SelectionSort(array, size);
                break;
            case '4':
                puts("You Picked Bubble Sort Algorithm");
                BubbleSort(array, size);
                break;
            case '5':
                puts("You Picked Quick Sort Algorithm");
                QuickSort(array, 0, size);
                break;
            default:
                puts("You inserted wrong number please try again with right number for specific algorithm.\n");
                PrintAlgorithmsTitles();
                break;
            }
    } while (algorithmPicker < 49 || algorithmPicker > 54);

}

//=======================================================================================



void InsertionSort(int array[], int end)
{
    for(int i = 1; i < end;i++)
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

void SelectionSort(int array[], int end)
{
}

void BubbleSort(int array[], int end)
{
}


void QuickSort(int array[], int start, int end)
{
}



int main()
{
    int size;
    do {

        printf("insert any size from 1 to 300\n");
        scanf("%d", &size);

        if (size > 300 || size < 1)
        {
            printf("You entered size out of range please ");
            size = 1;
            continue;
        }

        int array[size];

        puts("Fill The Array Please");

        GenerateFilledArray(array, size);

        if (!ValidateArray(array, size))
        {
            puts("Your input is not valid please make sure that all inputs are 0 or 1 or 2\n");
            size = 1;
            continue;
        }

        puts("Pick Algorithm To Sort The Array!");

        PrintAlgorithmsTitles();

        PickAlgorithm(array, size);

        PrintSortedArray(array, size);

        puts("If you wanna try again insert number or -1 to terminate.");
        scanf("%d", &size);


    } while (size != -1);
}
