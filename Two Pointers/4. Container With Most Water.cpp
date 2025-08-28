class Solution {
    public:
    
        int maxAreaOptimized(vector<int>& height){
            
            //Algo 2 (Two Pointer Approach):
            // 1. Select L = 0 , R = heights.size()-1
            // 2. Calculate the accumulated water between the heights L & R
            // 3. Current Accumulated water between heights L & R = (R - L) * min (heights[L] , heights[R])
            // 4. Keep track of MaxAccumulated water if every L & R
            // 5. Now, que: which one to move L or R? - Inc L if heights[L] is less than heights[R]
            // 6. Dec R if  heights[R] is less than heights[L]

            // Time Complexity Analysis:
            // We need to visit each element in heights[L] at least once 
            // So Overall O(N) where N is the length of given input array

            // Space Complexity Analysis
            // No extra space  O (1) = constant space 

            int L, R;
            int MaxWaterTrapped = 0, CurrWaterTrapped;

            L = 0;
            R = height.size()-1;
    
            while( L < R)
            {
                CurrWaterTrapped = (R-L)*min(height[L], height[R]);
                MaxWaterTrapped = max(MaxWaterTrapped, CurrWaterTrapped);
    
                if(height[L] <= height[R])
                    L++;
                else
                    R--;
    
            }
            return MaxWaterTrapped;
        }
    
        int maxArea(vector<int>& height) {
    
            return maxAreaOptimized(height);
    
            //Algo 1 (brute-force approach):
    
            // 1. select each of two heights and find the area 
            // 2. keep track of water trapped in those heights 
            // 3. Current Accumulated water between heights L & R = (R - L) * min (heights[L] , heights[R])
            // 4. Keep track of MaxWater trapped area
            int MaxWaterTrapped = 0, CurrWaterTrapped;
    
            for (int L = 0 ; L < height.size()-1 ; L++)
            {
                CurrWaterTrapped = 0;
    
                for(int R = L+1 ; R < height.size(); R++)
                {
                    CurrWaterTrapped = (R-L)*min(height[L], height[R]);
    
                    MaxWaterTrapped = max(MaxWaterTrapped, CurrWaterTrapped);
                }
            }
            return MaxWaterTrapped;
        }
    };