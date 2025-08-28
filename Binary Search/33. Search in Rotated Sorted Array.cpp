class Solution {
    public:
        int findElement(vector<int> nums, int L, int R, int target)
        {
            // This is normal binary search element algorithm which runs over sorted array
            while(L<=R)
            {
                int mid = (L + R)/2;
    
                if(nums[mid] == target)
                {
                    return mid;
                }
                else if(nums[mid] < target)
                {
                    L = mid+1;
                }
                else
                {
                    R = mid-1;
                }
    
            }
            return -1;
        }
        int search(vector<int>& nums, int target) {
    
    
            //first find the pivot element using binary search then find the element to be searched in that array
            // while finding pivot if we get a segment where it is in sorted order. then find the element in sorted array
            int mid = 0;
            int L = 0;
            int R = nums.size()-1;
            bool foundPivot = false;
            int pivotIndex = 0;
    
            while(L <= R)
            {
                //calculate mid index for binary search
                mid = (L+R)/2;
    
                if((L == R) && (L == mid))
                {
                    //this is the minimum element in an array
                    //which is also called as pivot
                    pivotIndex = mid;
                    break;
                }
    
                //check if left side segment is in sorted order
                if(nums[L] <= nums[mid])
                {
                    //If the target element is in sorted segment 
                    //safe to search for that element in it 
                    //return its index if found otherwise return -1
                    if((nums[L] <= target) && (target <= nums[mid]))
                    {
                        return findElement(nums, L, mid, target);
                    }
                    //check if both the segments are in sorted order
                    else if (nums[mid] < nums[R])
                    {
                        //check if target lies in second segment
                        if((nums[mid] <= target) && (target <= nums[R]))
                        {
                            return findElement(nums, mid, R, target);
                        }
                        // if the element didn't find in right sorted array
                        // then shrink R to mid
                        R = mid;
    
                    }
                    else 
                    {
                        //pivot is lying on the right segment
                        L = mid+1;
                    }
    
                }
                else
                {
                    //for finding pivot we are shrinking the window
                    R = mid;
                }
            }
            return findElement(nums, pivotIndex, nums.size()-1, target);
        }
    };