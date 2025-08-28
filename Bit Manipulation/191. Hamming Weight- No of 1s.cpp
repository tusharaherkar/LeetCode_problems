class Solution {
    //Que: Given a positive integer n, write a function that returns the number of set bits 
    // in its binary representation (also known as the Hamming weight).
    
    // Example:
    // Input: n = 11
    // Output: 3
    // Explanation:
    // The input binary string 1011 has a total of three set bits.

    public:
        int hammingWeightOptimized(int n) {
            // Algo 2:
            // Intution
            
            // Counting Set Bits (1s):
            // • By repeatedly applying the n &= (n-1) operation, the most significant bit (MSB) will eventually be 1, and all others to the right will be 0.
            // • The number of iterations it takes to reach 0 is equal to the number of set bits (1s) in the original number n. 

            int count = 0;
            while(n)
            {
                n &= (n-1);
                count++;
            }
            return count;

        }
        int hammingWeight(int n) {
            // Algo 1:
            // 1. Declare count as 0
            // 2. & each bit of given input with 0b01 and if it is set inc the count
            // 3. Right shit the input by 1 and then again do same unless whole input number become 0
            // 4. return count

            // Time Complexity Analysis:
            // O(1) : given input is of int type which is 4byte

            // Space Complexity Analysis
            // O(1): space complexity - No Extra space required

            return hammingWeightOptimized(n);
            
            int count = 0;
            while(n)
            {
                if(n & 0b01)
                    count++;
    
                n >>= 01;
            }
            return count;
        }
    };
