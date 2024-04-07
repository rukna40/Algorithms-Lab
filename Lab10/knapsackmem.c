#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int mat[100][100];

int knapsack(int w, int n, int weights[n], int value[n]) {
    if(mat[n][w]!=-1){
        return mat[n][w];
    }
    if (weights[n - 1] > w){
        mat[n][w] = knapsack(w, n - 1, weights, value);
    }
    else{
        mat[n][w] = max(knapsack(w, n - 1, weights, value),value[n-1]+knapsack(w-weights[n-1], n - 1, weights, value));
    }
    return mat[n][w];
}   

int main() {
    int weight[] = { 2, 1, 3, 2 };
    int value[] = { 12, 10, 20, 15 };
    int n = 4; 
    int w = 5; 

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            mat[i][j] = -1;
        }
    }
    int result = knapsack(w, n, weight, value);

    printf("Maximum value that can be obtained: %d\n", result);
}
