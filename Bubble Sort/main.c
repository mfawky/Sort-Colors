#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;

}
void BubbleSort(int *arr){
    for(int i=0; i < sizeof(arr)-1; i++){
        for(int j=0; j < sizeof(arr)-i-2 ; j++){
                if(arr[j] > arr[j+1]){
                    printf("sizeof %d of array: %d\n",arr[j],arr[j+1]);
                    swap(&arr[j],&arr[j+1]);
                    printf("sizeof %d of array: %d\n",arr[j],arr[j+1]);
                }
        }
    }
}


int main()
{
    int arr[]={1,20,50,9,7,4,3};
    BubbleSort(arr);
    for(int i=0; i < sizeof(arr)/sizeof(int); i++)
         printf("sizeof of array: %d\n",arr[i]);

    return 0;
}
