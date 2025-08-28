class Solution {
    // Que: A peak element is an element that is strictly greater than its neighbors.
    // Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
    // You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
    // You must write an algorithm that runs in O(log n) time.

    public:
        int findPeakElement(vector<int>& nums) {
            // Input: nums = [1,2,1,3,5,6,4]
            // Output: 5
            // Explanation: Your function can return either index number 1 
            // where the peak element is 2, 
            // or index number 5 where the peak element is 6.
            
            // Algo:
            // find peak element with the help of binary search
            // the criteria of peak element is It should be greater than its neibouring elements
            // 1. Set L = 0 and R = nums.size()-1
            // 2. So find mid = (L+R)/2
            // 3. if the element is greater than its neibouring elements then return that as peak element so return its index
            // 4. If the element is > than left neibour and It is less than right neibour then peak element may exists in right side of mid
            // 5. So set L = mid+1 in this case 
            // 6. If the element is < than left neibour and It is > right neibour then peak element exists is left side of mid
            // 7. So set R = mid-1 in this case 
            // 8. Do this till L <= R
            // 9. Corner cases to consider: 
            //          a. if nums.size == 1 then return 0
            //          b. if all are in descending order then eventually mid will be 0 in that case mid == 0 then check peak for 0th or 1st index element
            //          c. if all are in ascending order then eventually mid will be nums.size()-1 then in that case nums.size()-1 definitely will be peak
            
            // Time Complexity Analysis:
            // Each time we are divinding the elements in halfs
            // So, overall O(logN) where N is the number of elements in nums

            // Space Complexity Analysis
            // No extra space required
            // O(1) = constant space

            int L = 0, R = nums.size()-1;
            
            // Corner case 1:
            if(nums.size() == 1)
                return 0;
    
            int mid;
            bool probablepeak;
    
            while(L <= R)
            {
                mid = (L+R)/2;
                
                // Corner cases to consider: 
                // if all are in descending order then eventually mid will be 0 in that case mid == 0 then check peak for 0th or 1st index element
                if(mid == 0)
                {
                    if(nums[mid] > nums[mid+1])
                        return mid;
                    else
                        return mid+1;
                }    
                // Corner cases to consider: 
                // If all are in ascending order then eventually mid will be nums.size()-1 
                // then in that case nums.size()-1 definitely will be peak
                if(mid ==nums.size()-1)
                    return mid;
    
                // If the element is greater than its neibouring elements then
                // return that as peak element so return its index
                if( mid != 0 && mid != nums.size()-1 && nums[mid] > nums[mid-1]  && nums[mid] > nums[mid+1])
                {
                    return mid;
                }
                // If the element is < than left neibour and It is > right neibour then peak element exists is left side of mid
                // So set R = mid-1 in this case 
                else if(nums[mid] < nums[mid-1])
                {
                    R = mid-1;
                }
                // If the element is > than left neibour and It is less than right neibour then peak element may exists in right side of mid
                // So set L = mid+1 in this case 
                else if(nums[mid] < nums[mid+1])
                {
                    L = mid+1;
                }
            }
            return 0;
        }
    };