// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    // Que:
    // If input is given in binary format
    // Need to print longest chain of consecutive 1s which is know as maxWidth
    // Note: MaxWidth has to be power of 2 if the maxWidth is 5/6/7 we need to print that as 4
    // And StartingLane which is Bit position at which the maxWidth starts
    // BitPos  7654 3210
    //         |       |
    // Input 0b0111 1100   : MaxWidth = 4 startingLane = 2 (Note here consecutive set bits are 5 but 4 is a power of 2 hence 4)
    // Input 0b0110 0110   : MaxWidth = 2 startingLane = 1
    // Input 0b1111 1111   : MaxWidth = 8 startingLane = 0

    // Note: maxWidth is always 2^
    // 
    
    
int main() {
    // Write C code here

    //
    
    int Input = 0b10011; //0b01111100 = 4 st = 2
    //o/p
    // consecutive set bits = 2 startingLane = 2
    
    
    int BitPos = 0;
    int StartingLane = 0;
    int EndLane = 0;
    int MaxWidth = 0;
    int MaxStartingLane = 0;
    int flagInwhile = 0;
    
    
    while(Input)
    {
        if(Input&0b01)
        {
            flagInwhile = 0;
            StartingLane = BitPos;
            while(Input&0b01 != 0)
            {
                flagInwhile = 1;
                Input>>=0b01;
                BitPos++;
                
            }
            if( flagInwhile)
            {
                if(MaxWidth < BitPos-StartingLane)
                {
                    MaxWidth = BitPos-StartingLane;
                    MaxWidth = pow(2,(int)log2(MaxWidth));
                    MaxStartingLane = StartingLane;
                }
                
            
            }
            
        }
        Input>>=0b01;
        BitPos++;
        
    }
    printf("MaxWidth = %d\t StartingLane = %d\n", MaxWidth, MaxStartingLane);
    
    //O/P
    
    return 0;
}