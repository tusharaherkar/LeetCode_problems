/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct Number{

    int index;
    int val;

 } Num;

 int compartor(const void* A, const void* B)
 {
    Num* Anum = (Num*)A;
    Num* Bnum = (Num*)B;

    return (Anum->val - Bnum->val);

 }
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int* soln = (int *)malloc(2* sizeof(int));

    int i = 0;

    Num* arr = (Num*) malloc (numsSize * sizeof(Num));

    for(i = 0 ; i < numsSize ; i++)
    {
        arr[i].index = i;
        arr[i].val = nums[i];
        //printf("%d : %d \t", arr[i].index, arr[i].val); 
    }

    qsort(arr, numsSize, sizeof(arr[0]), compartor);


    // for(i = 0 ; i < numsSize ; i++)
    // {
    //     printf("%d : %d \t", arr[i].index, arr[i].val); 
    // }

    int L = 0;
    int R = numsSize-1;
    int currSum = 0;

    while(L < R)
    {
        currSum = arr[L].val + arr[R].val;

        if(currSum  == target)
        {
            soln[0] = arr[L].index;
            soln[1] = arr[R].index;
            break;
        }
        else if(currSum > target)
        {
            R--;
        }
        else
            L++;
    }
    
    

    *returnSize = 2;
    return soln;
    
}