// Online C compiler to run C program online
#include <stdio.h>
 
int partition(int* A, int startPos, int endPos)
{
    int pivotIndex = endPos;
    
    int trav = startPos;
    
    int correctPosIndex = startPos-1;
    
    while(trav < endPos)
    {
        if(A[trav] < A[pivotIndex])    
        {
            ++correctPosIndex;
            int temp = A[correctPosIndex];
            A[correctPosIndex] = A[trav];
            A[trav] = temp;
        }
        trav++;
    }
    ++correctPosIndex;
    //trav++;
    int temp = A[correctPosIndex];
    A[correctPosIndex] = A[pivotIndex];
    A[pivotIndex] = temp;
    return correctPosIndex;
}
void quickSort(int* A, int startPos, int endPos)
{
    if(startPos < endPos)
    {
        int partitionIndex = partition(A, startPos, endPos);
    
        quickSort(A, startPos, partitionIndex-1);
        quickSort(A, partitionIndex+1, endPos);    
    }
    
    
    
    
}
int main() {
    // Write C code here

    int A[5] = {5,3,4,2,1};
    quickSort(A, 0, 4);
    int i;
    for(i = 0 ; i < 5; i++)
    {
        printf("\t %d", A[i]);
    }
    printf("\n");

    return 0;
}