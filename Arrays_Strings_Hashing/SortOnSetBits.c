// Online C compiler to run C program online
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

typedef struct Number{
    int num;
    int pos;
    int countsetBits;
}Num;

Num objs[10];

int Input[10] = {5,2,3,9,4,6,7,15,32,14};
int computeSetBits(int n)
{
    int count = 0;
    
    if(n == 0)
        return 0;
        
    do
    {
        n = (n&(n-1));
        count++;
        
    }while(n);
    
    return count;
}
int comparator(const void *a, const void *b)
{
    Num* A = (Num*)a;
    Num* B = (Num*)b;
    return (B->countsetBits) - (A->countsetBits);
    
}
int main() {
    // Write C code here
    
    int i = 0;
    for(i = 0; i< 10; i++)
    {
        
        objs[i].num = Input[i];
        objs[i].pos = i;
        objs[i].countsetBits =  computeSetBits(Input[i]);
        
        
    }
    qsort(&objs[0], 10, sizeof(objs[0]), comparator);
    
    printf("sorted with countsetbits\n");
    for(i = 0; i< 10; i++)
    {
        printf("%d\t", objs[i].num);
    }
    printf("\n");
    return 0;
}