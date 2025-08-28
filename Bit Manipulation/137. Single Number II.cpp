// Que:
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

// Intution with Space Complexity( O(N)): 
// Write Map to store the freq of each element 
// return the element with freq 1

class Solution {
public:
    int singleNumberOptimized(vector<int>& nums) {
        // Intution:
        // each element in nums is 32-bit int
        // so each bit inside int in nums will be added and % with 3 to find the element which comes only once
        // why mod 3 because if the bit is set it will be added 3 times in sum
        // So for the number which appeared once will be added only once and mod 3 will result in that set bit 1

        
        //Algo 2:
        // 1. declare ans = 0
        // 2. run a loop for each bit in 32 bit int for each element in nums
        // 3. right shift nums to the appropriate place to take out the particular bit position in 32
        // 4. if the bit is set add it to the sum it will be added thrice if the number is appeared thrice
        // 5. So mod the sum with 3 (check intution)
        // 6. Make the number which appeared once by again left shifting it to the appropriate place


        int ans = 0;

        for(int i = 0; i < 32 ; i++)
        {
            int sum = 0;
            for(int j = 0 ; j < nums.size() ; j++)
            {
                if ((nums[j]>>i) & 0b01) 
                    sum++;
            }
            ans |= ((sum%3) << i);

        }
        return ans;
    }
    int singleNumber(vector<int>& nums) {

        // Algo 1 (using Hashmap method):
        // Intution with Space Complexity(O(N)):
        // Write Map to store the freq of each element 
        // return the element with freq 1

        // Time Complexity Analysis:
        // O(N) where N is the number of elements in nums

        // Space Complexity Analysis
        // hashmap is used in the proposed solutions of size worst case of size nearly = N
        // O(N) where N is the number of elements in nums
        
        return singleNumberOptimized(nums);
        
        // Map will be used to store the freq of elements in nums
        unordered_map <int, int> map;

        for(auto &it: nums)
        {
            map[it]++;
        }

        for(auto &it: map)
        {
            if(it.second == 1)
                return it.first;

        }
        return -1;
        
    }
};