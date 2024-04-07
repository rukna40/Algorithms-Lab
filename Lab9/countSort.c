#include<stdio.h>
#include<stdlib.h>

void countSort(int n, int arr[n]){
    int* count=calloc(n,sizeof(int));
    int* S=calloc(n,sizeof(int));
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]<arr[j]){
                count[j]++;
            }
            else{
                count[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        S[count[i]]=arr[i];
    }

    for(int i=0;i<n;i++){
        printf("%d\t",S[i]);
    }
    
}

int main(){
    int n=6;
    int arr[]={4,6,9,2,1,8};
    countSort(n,arr);
}