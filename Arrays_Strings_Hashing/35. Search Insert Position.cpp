// Que:
// Given a sorted array of distinct integers and a target value,
// return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Algo:
        // 1. Set L = 0 and R to the rightmost element
        // 2. check with the help of binary search whether target element exists or not
        // 3. If exists return the index
        // 4. If not check L is within range of nums array. If not swap with R
        // 5. check nums[L] > target if yes then L is the right index where we can insert the target 
        //    because nums[L] will be shifted to right by 1 index if we insert at L
        // 6. if no then L+1 would be right posittion to insert the target element

        // Time Complexity Analysis:
        // O (log N) as we are dividing the array in half

        // Space Complexity Analysis
        // O(1) = constant space

        int L = 0, R = nums.size()-1;
        int mid ;

        
        while(L <= R)
        {
            mid = (L+R)/2;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
                L = mid+1;
            else
                R = mid-1;
        }
        if(L >= nums.size())
            swap(L, R);

        if(nums[L] > target)
            return L;
        else
            return L+1;
        
        return 0;
        
    }
};