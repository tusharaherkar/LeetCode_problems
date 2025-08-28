// Que: Given a non-empty array of integers nums, every element appears twice except 
// for one. Find that single one.
// You must implement a solution with a linear runtime complexity and 
// use only constant extra space.

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            // Algo: 
            // 1. The property of XOR is if we XOR any number with itself it will result into 0
            // 2. Since all numbers appeared twice they all result in 0
            // 3. The number which is not duplicate will be remained if we XOR all given numbers
            // 4. The same intution is used in given input array

            // Time Complexity Analysis:
            // O(N) where N is the number of elements in given array

            // Space Complexity Analysis
            // O(1) - No extra space required which is constant space
            
    
            int remaining = 0;
    
            for(auto &it : nums)
            {
                remaining ^= it;
            }
            return remaining;
            
        }
    };