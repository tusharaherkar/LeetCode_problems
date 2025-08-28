class Solution {
    // Que:
    //Given an integer n, return an array ans of length n + 1 
    // such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

    // Example 1:
    // Input: n = 2
    // Output: [0,1,1]
    // Explanation:
    // 0 --> 0
    // 1 --> 1
    // 2 --> 10

    // Table chart
    // Decimal	Binary	Set Bits
    // 0		0	    0
    // 1		1	    1
    // 2		10	    1
    // 3		11	    2
    // 4		100	    1
    // 5		101	    2
    // 6		110	    2
    // 7		111	    3
    // 8		1000	1
    // 9		1001	2
    // 10		1010	2
    // 11		1011	3
    // 12		1100	2
    // 13		1101	3
    // 14		1110	3
    // 15		1111	4

    
public:
    vector<int> countBits(int n) {

        vector<int> ans;
        int currpow2=0;
        int nextpow = 2;

        for(int i = 0 ; i <= n ; i++)
        {
            

            if(i < 2)
            {    
                ans.push_back(i);
                continue;
            }
            
            // for checking i is power of 2 has 2 ways:
            // 1st Approach:
            // ex. 8 = 0b1000
            // Intution used: 
            // # Checking for Powers of 2:
            // • A number is a power of 2 if and only if it has exactly one bit set to 1 in its binary representation.
            // • If n & (n-1) equals 0, it means the number n has only one bit set, and therefore, it's a power of 2. 
            if((i & (i-1)) == 0)
            {
                //then it is power of 2
                ans.push_back(1);
                continue;
            }

            

            // 2nd Approach:
            // Keep track of currpow2 and calculate nextpow by 2*currpow2 
            // if(i == nextpow) // if i is power of 2
            // {
            //     ans.push_back(1);
            //     currpow2 = i;
            //     nextpow = currpow2 * 2;
            //     continue;
            // }

            ans.push_back(1+ans[i-currpow2]);


        }
        return ans;


        
    }
};