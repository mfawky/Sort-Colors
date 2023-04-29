#include <stdio.h>
#include ".\SortAlgrorithms.c"
#include ".\Utilities.c"

int main()
{
    int size;
    do
    {
        system("cls");
        printf("Insert any size from 1 to 300\n");
        scanf("%d", &size);

        if (size > 300 || size < 1)
        {
            printf("You entered size out of range please ");
            printf("Press any key to continue.........");
            getch();
            size = 1;
            continue;
        }

        int array[size];

        puts("Fill the array please (only accepts integers 0, 1, or 2)");

        GenerateFilledArray(array, size);

        if (!ValidateArray(array, size))
        {
            puts("Your input is not valid please make sure that all inputs are 0 or 1 or 2\n");
            printf("Press any key to continue.........");
            getch();
            size = 1;
            continue;
        }

        puts("Pick an algorithm to sort the array!");

        PrintAlgorithmsTitles();

        PickAlgorithm(array, size);

        PrintSortedArray(array, size);

        puts("If you wanna try again insert any number or -1 to terminate.");
        scanf("%d", &size);

    } while (size != -1);

    return 0;
}
