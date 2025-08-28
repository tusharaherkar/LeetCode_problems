class Solution {
    public:
        int BinarySearch(vector<int>& nums, int target, int StartIndex, bool IsStartingPos)
        {
            int L = StartIndex;
            int R = nums.size()-1;
            int returnIndex = -1;
            
            while(L <= R)
            {
                int mid = (L+R)/2;
    
                
                if(nums[mid] > target)
                {
                    R = mid -1;
                }
                else if(nums[mid] < target)
                {
                    L = mid + 1;
                }
                else if(nums[mid] == target)
                {
                    returnIndex = mid;

                    if(IsStartingPos)
                    {
                        R = mid-1;
                    }
                    else
                    {
                        L = mid+1;
                    }
                }
    
            }
            return returnIndex;
    

        }
        vector<int> searchRangeOptimised(vector<int>& nums, int target) {
            
            // Intution:
            // First use Binary Search to get the left starting position of target
            // Then use Binary Search to get the right ending position of target in nums

            // Time Complexity Analysis:
            // We are dividing the array in half each time 
            // Worst case O(logN) where N is the number of elements in nums input array


            // Space Complexity Analysis
            // No extra space required 
            // O(1) = constant space 
            vector <int> Soln;
    
            if(nums.size() == 0)
            { 
                Soln.push_back(-1);
                Soln.push_back(-1);
                return Soln;
            }
            if(nums.size() == 1 && target == nums[0])
            {
                Soln.push_back(0);
                Soln.push_back(0);
                return Soln;  
            }
            else if(nums.size() == 1 && target != nums[0])
            {
                Soln.push_back(-1);
                Soln.push_back(-1);
                return Soln;
            }
            int leftStartpos = BinarySearch(nums, target, 0, true);
            int rightEndpos = (leftStartpos == -1 ? -1 : BinarySearch(nums, target, leftStartpos, false));
            Soln.push_back(leftStartpos);
            Soln.push_back(rightEndpos);
            return Soln;
            
        }
        vector<int> searchRange(vector<int>& nums, int target) {

            return searchRangeOptimised(nums, target);
            
            // Intution: 
            // When the element is found by binary search algo 
            // then find the starting pos and ending pos 
            // with the help of while loop but this would take worst case O(N) for finding start and end  pos

    
            // Algo:
            // worst case the last while loops will take O(N) if all elements in nums are target elements
    
            int L = 0;
            int R = nums.size()-1;
            vector <int> Soln;
    
            if(nums.size() == 0)
            { 
                Soln.push_back(-1);
                Soln.push_back(-1);
                return Soln;
            }
            if(nums.size() == 1 && target == nums[0])
            {
                Soln.push_back(0);
                Soln.push_back(0);
                return Soln;  
            }
            else if(nums.size() == 1 && target != nums[0])
            {
                Soln.push_back(-1);
                Soln.push_back(-1);
                return Soln;
            }

            bool found = false;
            int foundIndex = 0;
            
            while(L <= R)
            {
                int mid = (L+R)/2;
    
                if(nums[mid] == target )
                {
                    found = true;
                    foundIndex = mid;
                    break;
                }
                else if(nums[mid] > target)
                {
                    R = mid -1;
                }
                else 
                {
                    L = mid + 1;
                }
    
            }
    
            if(found)
            {
                int left = foundIndex;
                // go to left and find left index
                while(left >= 0)
                {
                    if(nums[left] != nums[foundIndex])
                    {
                        break;
                    }
                    left--;
                }
                Soln.push_back(left+1);

                int right = foundIndex;
                // go to right and find the right index
                while(right <= nums.size()-1)
                {
                    if(nums[right] != nums[foundIndex])
                    {
                        break;
                    }
                    right++;
                }
                Soln.push_back(right-1);
            }
            else 
            {
                Soln.push_back(-1);
                Soln.push_back(-1);
                
            }
            return Soln;
        }
    };