#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int knapsack(int* w, int* v, int b, int n) {
    int maxVal = 0;
    int sack = 0;

    for (int i = 1; i < pow(2, n); i++) {
        int temp = i;
        int totalWeight = 0;
        int totalValue = 0;
        int index = 0;

        while (temp) {
            if (temp & 0x1) {
                totalWeight += w[index];
                totalValue += v[index];
            }
            index++;
            temp = temp >> 1;
        }

        if (totalWeight <= b && totalValue > maxVal) {
            maxVal = totalValue;
            sack = i;
        }
    }

    return sack;
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int capacity = 8;
    int numItems = 4;

    int result = knapsack(weights, values, capacity, numItems);

    printf("Selected items: ");
    for (int i = 0; i < numItems; i++) {
        if (result & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
