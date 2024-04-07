#include <stdio.h>

int n=4;
int minCost = 9999999;

void assign(int costMat[][n],int cost,int i,int assignment[]){
    if(i==n){
        if(cost<minCost){
            minCost=cost;
        }
        return;
    }    
    for(int j=0;j<n;j++){
        if (!assignment[j]){
            assignment[j] = i;
            assign(costMat,cost+costMat[i][j],i+1,assignment);
            for(int k=0;k<n;k++){
                printf("%d ",assignment[k]);
            }
            printf("\n");
            assignment[j] = 0;
        }
    }
}

int main() {
    int costMat[][4] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int assignment[n];
    for (int i = 0; i < n; i++) {
        assignment[i] = 0;
    }

    assign(costMat, 0, 0, assignment);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}