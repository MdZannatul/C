#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int lb, int mid, int ub, int b[]) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (k = lb; k <= ub; k++) {
        a[k] = b[k];
    }
}

void mergeSort(int a[], int lb, int ub, int b[]) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid, b);
        mergeSort(a, mid + 1, ub, b);
        merge(a, lb, mid, ub, b);
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[1000], b[1000];

    srand(time(NULL));

    printf("Random Elements:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    mergeSort(a, 0, n - 1, b);

    printf("\n\nMerge Sorted Elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}


/*

//quicksort----------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb + 1;
    int end = ub;

    while (start <= end) {
        while (start <= end && a[start] <= pivot) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }

        if (start < end) {
            swap(&a[start], &a[end]);
        }
    }

    swap(&a[lb], &a[end]);

    return end;
}

void quicksort(int a[], int lb, int ub)
{
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int main()
{
    int a[1000], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    srand(time(0));
    printf("Randomly generated array:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    quicksort(a, 0, n - 1);
    printf("\n\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}




//knapsack---------------------------

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


//mcm--------------------------

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








//dijkstra---------------------------

#include <stdio.h>
#include <limits.h>

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[][100], int src, int V) {
    int dist[V];

    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, V);

    return 0;
}






*/
