// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void Combine(int* A, int Low, int mid, int High)
{
    int i = Low;
    int j = mid+1;
    
    int len1 = mid-Low+1;
    int len2 = High-mid;
    
    int mergedTrav = Low;
    
    int L[len1], R[len2];
    
    // Copy two arrays 
    int trav = 0;
    for(trav = 0; trav  < len1; trav++)
        L[trav] = A[i++];
    
    for(trav = 0; trav < len2; trav++)
        R[trav] = A[j++];
    
    i = 0;
    j = 0;
    
    while(i < len1 && j < len2)
    {
        if(L[i] <= R[j])
            A[mergedTrav] = L[i++];
        else
            A[mergedTrav] = R[j++];
        mergedTrav++;
    }
    while(i < len1)
        A[mergedTrav++] = L[i++];
    
    while(j < len2)
        A[mergedTrav++] = R[j++];
    
}
int mergeSort(int *A, int Low, int High)
{
    if(Low < High)
    {
        int mid = Low+ ((High-Low)/2);
        mergeSort(A, Low, mid);
        mergeSort(A, mid+1,High);
        Combine(A, Low, mid, High);
    }
    
}
// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}