#include <stdio.h>
#include <time.h>
#include<stdlib.h>
void merge(int low, int mid, int high, int arr[]);
void mergeSort(int low, int high, int arr[])
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
}
void merge(int low, int mid, int high, int arr[])
{
    int i = low;
    int j = mid + 1;
    int temp[1000];
    int k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (int i = low; i <= high; i++)
        arr[i] = temp[i];
}

int main()
{
    int n;
    printf("ENter the numebr of elements:");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    printf(" elements are :");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

    clock_t start = clock();
    mergeSort(0, n - 1, arr);
    clock_t end = clock();

    printf("ELmenets after sortinf are:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double t = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to execute: %10f seconds\n", t);
    return 0;
}
