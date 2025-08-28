class Solution {
public:
    int minSubArrayLenOptimized(int target, vector<int>& nums) {
        // Algo 2 (Sliding Window):
        // 1. Declare L = 0, R = 0;
        // 2. Gradually inc R and keep currSum of nums[R] if it is >= target 
        // 3. Note the length and keep track of minlen
        // 4. then try to shrink the window with L++ and check if still >= target 
        // 5. If yes Note the length and keep track of minlen try to shrink till < target
        // 6. Again, inc R and do the same till R reaches nums.size()-1

        // Time Complexity Analysis:
        // Sliding window takes linear time complexity of O(N)
        // O(N) where N is the number of elements in nums array

        // Space Complexity Analysis
        // No extra space required
        // O(1) = constant space

        // Declare L = 0, R = 0;
        int L  = 0, R = 0;

        int currSum = 0;
        int minLen = INT_MAX;

        // Gradually inc R 
        while(R < nums.size())
        {
            //keep currSum of nums[R] 
            currSum+= nums[R];
            
            //if currSum is >= target            
            while(currSum >= target)
            {
                //Note the length and keep track of minlen
                // Try to shrink the window with L++ 
                // check if still >= target 
                // If yes Note the length 
                // keep track of minlen try to shrink till < target
                minLen = min(minLen, R-L+1);
                currSum -= nums[L];
                L++;
            }
            //Inc R and do the same till R reaches nums.size()-1
            R++;
        }
        return (minLen == INT_MAX? 0 : minLen);

    }
    int minSubArrayLen(int target, vector<int>& nums) {
        
        return minSubArrayLenOptimized(target, nums);

        // Algo 1 (Brute Force Approach):
        // 1. Take all the subarrays from 0 till n-1 in O(N^2) time complexity 
        // 2. return minimum length of subarray which satisfies condition >= target

        int minlen = INT_MAX;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int currSum = 0;
            for(int j = i ; j < nums.size(); j++)
            {
                currSum += nums[j];
                if(currSum >= target)
                {
                    minlen = min(minlen, j-i+1);
                    break;
                }   
            }
        }
        return (minlen == INT_MAX ? 0 : minlen);

        
    }
};