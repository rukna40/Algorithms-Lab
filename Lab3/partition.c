#include <stdio.h>

int partition(int set[], int n,int sum){
    if (n==0)
        return 0;

    if(sum==0){
        return 1;
    }

    if(set[n-1]>sum){
        return partition(set,n-1,sum);
    }
    return partition(set,n-1,sum)||partition(set,n-1,sum-set[n-1]);;
}

int isPartition(int set[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    if (sum % 2 != 0) {
        return 0;
    }
    return partition(set,n,sum/2);
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isPartition(arr, n)) {
        printf("Partition possible\n");
    } else {
        printf("Partition not possible\n");
    }

    return 0;
}