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

