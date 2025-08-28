class Solution {
    //Que: Given n non-negative integers representing an elevation map 
    // where the width of each bar is 1, compute how much water it can trap after raining.

    public:
        int trap(vector<int>& height) {

            //Algo:
            // Ex.: [0,1,0,2,1,0,1,3,2,1,2,1]
            //
            //  __						 
            // |  |                     
            // |  |                     
            // |  |                     
            // |  |                      __
            // |  |                     |  |
            // |  |                     |  |
            // |  |        __           |  |
            // |  |       |  |          |  |
            // |  | . . . |  |  . .  .  |  |
            // |  |       |  |          |  |
            // __________________________________
            // 10          2			  7
            // Intution of two pointer approach
            // For height 2 doesn't matter what heights are coming in between 2 & 10 
            // because 10 is the max height which came when traversing from left
            // For height 2 doesn't matter what heights are coming in between 2 & 7
            // because 7 is the max height which came when traversing from right
            // so the water accumulated above height 2 will be min (10, 7) - current height i.e.2
            // So it will be 7 units of water - 2 units of water = 5 units of water 

            // Algo (Two pointer Approach):
            // 1. Traverse from left - Maintain prefixMaxHeights array to track max heights from left side of the array
            // 2. Traverse from right- Maintain suffixMaxHeights array to track max heights from right side of the array
            // 3. Again, traverse the given array and calculate the rain water trapped for all heights
            // 4. Rain water trapped for a current height 
            // 5. Keep track of trapped water till now by summing calculated trapped water on step 4
            
            // Time Complexity Analysis:
            // We have to traverse each element atleast once 
            // So, overall O(N)

            // Space Complexity Analysis
            // prefixMaxHeights & suffixMaxHeights are maintained extra 
            // O(2N) ~= O(N) where N is the number of elemenets given heights

            vector<int> leftmax(height.size(), 0);
            vector<int> rightmax(height.size(), 0);
    
            int leftMaxie=0;
            int rightMaxie=0;
    
            //cout<< "leftMax: ";
            for(int i = 0 ; i < height.size() ; i++)
            {
                leftMaxie = max(leftMaxie, height[i]);
                leftmax[i] = leftMaxie;
                //cout<< " " << leftmax[i];
            }
            //cout<<endl;
    
            rightMaxie = 0;
            //cout<< "rightMax: ";
            for(int i = height.size()-1 ; i >=0 ; i--)
            {
                rightMaxie = max(rightMaxie, height[i]);
                rightmax[i] = rightMaxie;
                //cout<< " " << rightmax[i];
    
            }
            
            ////cout<<endl;
            int trapWater = 0;
            for(int i = 0 ; i < height.size() ; i++)
            {
                trapWater += min(leftmax[i], rightmax[i]) - height[i];
            }
            return trapWater;
    
    
            return 0;
            
        }
    };