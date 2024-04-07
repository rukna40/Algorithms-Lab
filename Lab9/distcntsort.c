#include <stdio.h>
#include <stdlib.h>

void sort(int n, int arr[]){
    int* count=(int*)calloc(n,sizeof(int)); 
    int* output=(int*)calloc(n,sizeof(int)); 
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    
    for (int i=1;i<n;i++) {
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<n;i++){
        printf("%d\t",output[i]);
    }
}

int main(){
    int arr[]={1,2,2,2,1,1,1,6,7,3};
    sort(10,arr);
}
