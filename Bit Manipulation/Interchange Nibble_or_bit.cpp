#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// Que 1:
// You will be given with input value in integer
// You need to interchange nibble positions

// Example
// Input:  0xABCD EFAB
//           \/\/ \/\/
// Output: 0xBADC FEBA <-- 4-4 nibbles are interchanged

// Que 2:
// You will be given with input value in integer
// You need to interchange bit positions

// Example
// Input:  0b 1101 1010
//            \/\/ \/\/
// Output: 0b 1110 0101 <-- 1-1 are interchanged




int main()
{
    // Here the Soln is given for Que1 
    // But Que2 also can be solved with similar approach 

    long input;
    long inputLeft4;
    long inputRight4;
    
    cin>> hex >>input;
    cout << "0x"  << hex << input <<endl;

    inputLeft4  = ((input&0x0F0F0F0F) << 4);
    inputRight4 = ((input&0xF0F0F0F0) >> 4);
    input = (inputLeft4|inputRight4); 
    
    cout << "0x" << hex << input <<endl;

    return 0;
}