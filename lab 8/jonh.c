#include <stdio.h>

#define MAX 20

int perm[MAX];
int dir[MAX]; // -1 = left, +1 = right
int n;

// Check if k is mobile
int isMobile(int k) {
    int pos;

    // find position of k
    for (int i = 0; i < n; i++) {
        if (perm[i] == k) {
            pos = i;
            break;
        }
    }

    int next = pos + dir[pos];

    if (next < 0 || next >= n)
        return 0;

    if (perm[pos] > perm[next])
        return 1;

    return 0;
}

// Find largest mobile element
int getLargestMobile() {
    int maxMobile = 0;

    for (int i = 0; i < n; i++) {
        if (isMobile(perm[i])) {
            if (perm[i] > maxMobile)
                maxMobile = perm[i];
        }
    }

    return maxMobile;
}

// Print permutation
void printPermutation() {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Get index of value
int getIndex(int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == value)
            return i;
    }
    return -1;
}

// Reverse directions of all elements greater than k
void reverseDirections(int k) {
    for (int i = 0; i < n; i++) {
        if (perm[i] > k)
            dir[i] = -dir[i];
    }
}

int main() {
    printf("Enter n: ");
    scanf("%d", &n);

    // initialization
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1; // all left initially
    }

    printPermutation();

    while (1) {
        int k = getLargestMobile();

        if (k == 0)
            break;

        int pos = getIndex(k);
        int next = pos + dir[pos];

        // swap k with adjacent element
        int temp = perm[pos];
        perm[pos] = perm[next];
        perm[next] = temp;

        temp = dir[pos];
        dir[pos] = dir[next];
        dir[next] = temp;

        // reverse directions of elements greater than k
        reverseDirections(k);

        printPermutation();
    }

    return 0;
}