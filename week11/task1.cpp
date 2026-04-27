#include <stdio.h>
#include <stdlib.h>

//---COUNT SORT---
void countingSort(int arr[], int n) {
    int i, max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    for(i = 0; i <= max; i++)
        count[i] = 0;

    for(i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for(i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}


//---MERGE SORT---
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//---HEAP SORT---
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;

    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void display(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, choice, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\n---SORT MENU---\n");
    printf("\n1. Counting Sort\n2. Merge Sort\n3. Heap Sort\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            countingSort(arr, n);
            printf("Sorted array using Counting Sort:\n");
            display(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            printf("Sorted array using Merge Sort:\n");
            display(arr, n);
            break;
        case 3:
            heapSort(arr, n);
            printf("Sorted array using Heap Sort:\n");
            display(arr, n);
            break;
        case 4:
        	exit(0);
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
