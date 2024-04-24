#include <stdio.h>
#include <limits.h>

int p[100][100];

void matrixChainOrder(int dims[], int n) {
    int cost[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int temp = cost[i][k] + cost[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (temp < cost[i][j]) {
                    cost[i][j] = temp;
                    p[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Cost Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) {
                printf("%d ", cost[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    printf("Cost = %d\n", cost[1][n]);

    printf("Optimal Parenthesization:\n");
    print(1, n);
    printf("\n");
}

void print(int A, int B)
{
    if (A == B)
    {
        printf("A%d", A);
        return;
    }
    printf("(");
    print(A, p[A][B]);
    print(p[A][B] + 1, B);
    printf(")");
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1];
    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dims[i]);
    }

    matrixChainOrder(dims, n);

    return 0;
}


