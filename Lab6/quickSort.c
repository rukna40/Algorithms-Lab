#include <stdio.h>

int opcount;

void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int* arr, int low, int high){
    int i = low; 
    int j = high+1; 
    int pivot=arr[low];
    while (i<j){
        while (arr[i] <= pivot && i<high+1)  { 
            i++; 
        }
        while (arr[j] >= pivot && j>low) { 
            j--; 
        }
        if(i<j)
            swap(&arr[i], &arr[j]); 
    }
    swap(&arr[low], &arr[j]); 
    return j;
}

void sort(int* arr, int low, int high){

    if (low<high){
        int splitEle=partition(arr,low,high);
        sort(arr,low,splitEle-1);
        sort(arr,splitEle+1,high);
    }
}

int main()
{
    int n = 11;
    int arr[] = {1, 5, 2, 8, 3, 4, 5, 7, 1, 9, 0};
    sort(arr, 0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}