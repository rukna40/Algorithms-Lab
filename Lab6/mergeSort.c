#include <stdio.h>

int opcount;
void merge(int* arr, int l, int r, int m){
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    int i=0,j=0,k=l;
    while (i<n1 && j<n2){
        if(L[i]>R[j]){
            arr[k]=R[j];
            j++;
        }
        else{
            arr[k]=L[i];
            i++;
        }
        k++;
    }
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void sort(int* arr, int l, int r){
    if (l<r){
        int m = (l+r)/2;
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr,l,r,m);
    }
}

int main()
{
    int n = 11;
    int arr[] = {1, 5, 2, 8, 3, 4, 5, 7, 1, 9, 0};
    sort(arr, 0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



