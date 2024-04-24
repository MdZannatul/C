#include <stdio.h>

int max(int a, int b) {
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int knapsack(int n, int W, int weight[], int value[], int V[][100]) {
    for (int w = 0; w <= W; w++) {
        V[0][w] = 0;
    }

    for (int i = 0; i <= n; i++) {
        V[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                if (value[i - 1] + V[i - 1][w - weight[i - 1]] > V[i - 1][w]) {
                    V[i][w] = value[i - 1] + V[i - 1][w - weight[i - 1]];
                } else {
                    V[i][w] = V[i - 1][w];
                }
            } else {
                V[i][w] = V[i - 1][w];
            }
        }
    }

    return V[n][W];
}

void printTable(int n, int W, int V[][100]) {
    printf("\nKnapsack Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%2d ", V[i][w]);
        }
        printf("\n");
    }
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[100], value[100];
    int V[100][100];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapsack(n, W, weight, value, V);


    printTable(n, W, V);

    printf("\nMaximum Value: %d\n", maxValue);

    return 0;
}

