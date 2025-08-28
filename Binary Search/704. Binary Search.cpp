class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // Algo:
            // 1. This is standard Binary Search algorithm
            // 2. mid = (L+R)/2
            // 3. check if target exists at nums[mid] if yes return the index mid
            // 3. if nums[mid] < target search in right part of array i.e. shift L to mid+1
            // 4. if nums[mid] > target search in left part of array i.e. shift R to mid-1
            // 5. go on computing next mid i.e. step 2 unless and until L <= R
            
            // Time Complexity Analysis:
            // Every time we are divinding array in half
            // So overall O(logN)

            // Space Complexity Analysis
            // No extra space required 
            // O(1) = constant space
            

            int mid;
            int L = 0 , R = nums.size()-1;
    
            while(L <= R)
            {
                mid = (L+R)/2;
    
                if(nums[mid] == target)
                    return mid;
    
                if(nums[mid] > target)
                    R = mid -1;
                else
                    L = mid+1;
                
    
            }
            return -1;
    
            
        }
    };