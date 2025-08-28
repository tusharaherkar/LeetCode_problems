void RepeatedtoNonRepeated_SortedArray(int *arr, int N, int *NoofUniqueElements)
{
    //start replacing elements from array Index 1
    int replacebleIdx = 1;

    // make prev element as arr[0]
    int prev = arr[0];

    // start Iterating from index 1
    int Iter = 1;

    //till last element
    while(Iter < N)
    {
        //if prev element is not equal to current element then replace it with replacebleIdx
        if(prev != arr[Iter])
        {
            
	        arr[replacebleIdx] = arr[Iter];
            prev = arr[Iter];
            replacebleIdx++;
        }
        Iter++;
    }

    *NoofUniqueElements = replacebleIdx;
    
    // Make all other repeatating elements as -1 
    while(replacebleIdx < N)
    {
        arr[replacebleIdx] = -1;
    }
}