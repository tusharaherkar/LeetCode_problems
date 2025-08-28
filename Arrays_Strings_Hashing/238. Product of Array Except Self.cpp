class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
    
            //Algo:
            // 1. prodPrefix will maintain product of visited nodes from left side without currElement 
            // 2. prodSuffix will maintain product of visited nodes from right side without currElement 
            // Note: starting element for prodPrefix & prodSuffix is 1 
            // 3. Final Soln will be Soln[i] = prodPrefix[i] * prodSuffix[i]
    
            // Time Complexity Analysis:
            // Traversing each element for prodPrefix will take O(N)
            // Traversing each element for prodSuffix will take O(N)
            // So, O(N) + O(N) = O(2N) ~= O(N)
    
            // Space Complexity Analysis
            // prodPrefix & prodSuffix will occupy O(N)
            // So, overall O(N)
    
            vector <int> prodPrefix(nums.size());
            vector <int> prodSuffix(nums.size());
    
            int temp = 1;
    
            // 1. prodPrefix will maintain product of visited nodes from left side without currElement 
            for(int i = 0 ; i < nums.size() ; i++)
            {
                prodPrefix[i] = temp;
                temp*=nums[i];
            }
    
            // 2. prodSuffix will maintain product of visited nodes from right side without currElement 
            temp = 1;
            for(int i = nums.size()-1; i >= 0 ; i--)
            {
                prodSuffix[i]  = temp;
                temp*=nums[i];
            }
            // 3. Final Soln will be Soln[i] = prodPrefix[i] * prodSuffix[i] 
            // We are storing back to prodPrefix to save some extra space
            for(int i = 0 ; i < nums.size() ; i++)
            {
                prodPrefix[i] *= prodSuffix[i];
            }
            
            //return prodPrefix
            return prodPrefix;
    
            
        }
    };