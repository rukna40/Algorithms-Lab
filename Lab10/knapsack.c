#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void knapsack(int w, int n, int weights[n], int value[n]) {
    int mat[n + 1][w + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                mat[i][j] = 0;
            else if (j - weights[i - 1] < 0) {
                mat[i][j] = mat[i - 1][j];
            } else {
                mat[i][j] = max(mat[i - 1][j], value[i - 1] + mat[i - 1][j - weights[i - 1]]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int weight[] = { 2, 1, 3, 2 };
    int value[] = { 12, 10, 20, 15 };
    knapsack(5, 4, weight, value);
}
