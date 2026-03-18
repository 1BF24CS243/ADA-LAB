#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(1)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            break;
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}

int main()
{
    int n;

    printf("Enter no of elements u wish to enter: ");
    scanf("%d",&n);

    int a[n];


    srand(time(NULL));


    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }

    printf("Unsorted Array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    int start = clock();

    quicksort(a,0,n-1);

    int end = clock();

    printf("\nSorted Array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to execute: %f seconds\n", time_taken);

    return 0;
}