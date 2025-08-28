#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// Que:
// You will be given with input value in integer
// Low are Bit positions and Value in integer which is to be set in bitpositions 
// denoted by Low and High

// Example:
//     bitpositions:   8 7654 3210    
//      int input = 0b 1 0100 1101 = dec 333
//      Low = 2 and High = 4 
// So we need to set Value = 101 at postions starting from Low till High

// final output should be 0b 1 0101 0101 = dec 341 


int SetBitPositionValue(int input, int Value, int Low, int High)
{
    // Alternative 1:
    // travel 1 to the position till low (1 << low) i.e. 0b0000000100 
    // negation of  0b0000000100 make that low bit disbaled => (~0b0000000100 = 0b111111011)
    // if we can make the same bit disabled in input by ANDing it with input
    // Do the same from low till high
    // then return (input | (Value<<Low));

    int disableBits = Low;
    while(disableBits != High)
    {
        input &= ~(1<<disableBits);
        disableBits++;
    }

    // Alternative 2:
    // The above approach will take time complexity of while loop
    // Instead we can make use of one of the beutiful concept of n-1
    // if left shift to 1 position ahead of high-low i.e. 4-2+1 = 3 i.e. (1 << 3 =  0b1000)
    // Negate one from above binary will end up in 0b0111  
    // make it trave to <<low
    // 0b00011100 <-- here we could make 1's travel to exactly the place where we need to disable the bits
    // Now simply ~ negation will make them disable i.e. ~0b00011100 = 0b1111100011 <-- this is the bitmask
    // Now bitwise AND(&) this with the original input will disable the bits 
    // then return (input | (Value<<Low));

    int bitmask = (1 << (High - Low + 1));
    bitmask-=1;
    bitmask <<= Low;
    bitmask = ~(bitmask);
    
    input &= bitmask;


    return (input | (Value<<Low));
    
}
int main()
{
    int input, Val, Low, High;
    cin>>input;
    cin>>Val;
    cin>>Low;
    cin>>High;
    cout << SetBitPositionValue(input, Val, Low, High);

    return 0;
}