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
