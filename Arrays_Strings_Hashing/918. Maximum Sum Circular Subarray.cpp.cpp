class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Intution:
        // Noncicular Array : MaxSum is calculated by kadane's algo
        // Circular Array   : MaxSum is nothing but TotalSum - minSum and minSum can be found out by kadane's algo
        
        // So maxSubarraySumCircular = max (Max of Noncicular Array, Max of Circular Array)
        
        // Corner case : if all are negative numbers 
        // In that case TotalSum - minSum = 0 i.e. minSum subarray will be whole array so TotalSum and minSum will be same


        int maxSum = nums[0];
        
        int minSum = nums[0];

        int TotalSum = nums[0];

        int CurrSumMax =  nums[0];
        int CurrSumMin =  nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            //MaxSum is calculated by kadane's algo
            CurrSumMax = max(CurrSumMax+nums[i], nums[i]); 
            maxSum = max(maxSum, CurrSumMax);

            //MinSum is calculated by kadane's algo
            CurrSumMin = min(CurrSumMin+nums[i], nums[i]);
            minSum = min(minSum, CurrSumMin);

            //TotalSum is needed for calculation of max of circular array
            TotalSum += nums[i]; 
        }
        
        //Corner case given in algo is handled here
        return ((TotalSum - minSum == 0) ?  maxSum : max(maxSum, TotalSum - minSum));
        
    }
};