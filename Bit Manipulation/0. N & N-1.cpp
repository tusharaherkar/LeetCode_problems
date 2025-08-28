// This is the Informative page not code or any solution to question:
// In the binary number system, the expression n & (n-1) is significant because it efficiently eliminates the least significant bit (LSB) set to 1 in the binary representation of n. 
// This property is useful in various applications, including counting set bits, determining if a number is a power of 2, and bit manipulation tasks. 

// 1. Eliminating the Least Significant Bit (LSB):
// • The bitwise AND operation (&) compares each bit of n with the corresponding bit of n-1.
// • When n is a power of 2, the least significant bit (LSB) is the only bit set to 1. Subtracting 1 from a power of 2 sets all the bits to the right of the LSB to 1, and the LSB to 0.
// • When the bitwise AND is performed between n and n-1, the LSB is always eliminated, as the corresponding bit in n-1 is 0. 

// 2. Counting Set Bits (1s):
// • By repeatedly applying the n &= (n-1) operation, the most significant bit (MSB) will eventually be 1, and all others to the right will be 0.
// • The number of iterations it takes to reach 0 is equal to the number of set bits (1s) in the original number n. 

// 3. Checking for Powers of 2:
// • A number is a power of 2 if and only if it has exactly one bit set to 1 in its binary representation.
// • If n & (n-1) equals 0, it means the number n has only one bit set, and therefore, it's a power of 2. 

// 4. Clear all the set bits except rightmost set bit
// return n & ~(n-1)

// Example:
// Let's say n = 10 (binary: 1010). 

// • n - 1 = 9 (binary: 1001)
// • n & (n-1) = 1010 & 1001 = 1000 = 8 (binary: 1000)
// As you can see, the least significant bit (the rightmost '1' in 1010) has been eliminated. This is a key characteristic of the n & (n-1) operation in binary number systems. 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Checking Whether K-th Bit is Set or Not.cpp
mask = (1<<k);
if(input & mask)
    cout << "set" << endl;
else
    cout << "Not Set" << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Clearing the K-th bit of a number.cpp
mask = ~(1<<k);
return input & mask;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Setting the K-th bit of a number.cpp
mask = (1<<k);
return input |= mask;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Toggling the K-th bit of a number.cpp
mask = (1<<k);
return input ^= mask;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
