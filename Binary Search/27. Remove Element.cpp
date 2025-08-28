class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Algo:
        // 1. traverse the array from beginning
        // 2. if the nums[i] == val then swap it with end and delete end 
        // 3. In such case dont update traversal var i as again we need to check the swapped element
        // 4. Otherwise Inc i
        // 5. Return the size of nums as return 
        
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == val)
            {
                swap(nums[i], nums[nums.size()-1]);
                nums.pop_back();
            }   
            else
                i++;

        }
        return nums.size();
        
    }
};