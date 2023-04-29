#define GetArrayLength(arr) (sizeof(arr) / sizeof(arr[0]))

int ValidateArray(int array[], int size)
{
    int i = 0;

    if (sizeof(array) == 1 && (array[i] >= 0 || array[i] <= 2))
    {
        return 1;
    }

    for (; i < size; i++)
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
    for (int i = 0; i < n; i++)
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
        switch (algorithmPicker)
        {
        case '1':
            puts("You picked Insertion Sort algorithm");
            InsertionSort(array, size);
            break;
        case '2':
            puts("You picked Merge Sort algorithm");
            MergeSort(array, 0, size - 1);
            break;
        case '3':
            puts("You picked Selection Sort algorithm");
            SelectionSort(array, size);
            break;
        case '4':
            puts("You Picked Bubble Sort Algorithm");
            BubbleSort(array, size);
            break;
        case '5':
            puts("You picked Quick Sort algorithm");
            QuickSort(array, 0, size);
            break;
        default:
            puts("You inserted wrong number please try again with right number for specific algorithm.\n");
            PrintAlgorithmsTitles();
            break;
        }
    } while (algorithmPicker < 49 || algorithmPicker > 54);
}