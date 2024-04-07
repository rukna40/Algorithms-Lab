#include <stdio.h>

int opcount;
void sort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int ele = arr[i];
        while(j >= 0 && arr[j] > ele){
            arr[j+1] = arr[j];
            j--;
        }  
        arr[j+1] = ele;
    }
}

int main()
{
    int n = 11;
    int arr[] = {1, 5, 2, 8, 3, 4, 5, 7, 1, 9, 0};
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
