class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
    
            //Corner Case 1:
            if(nums.size() <= 1)
            {
                return nums.size();
            }
            // Algo / Intution:
            //Ex . [5, 4, 100, 1, 200, 2, 101, 3]
            // 1. Insert the elements in unordered_set <5, 4, 100, 1, 200, 2, 101, 3>
            // 2. Traverse the elements in given array
            // 3. If the left neighbor of curr element is not present then this element is starting of consecutive subsequence
            // 3. for such left neighbor absent curr element keep on ++ that element in while and check if that series is present in set
            // 4. Once we check that series length keep track of such longest consecutive sequence.
            // 5. If left neighbor of curr element is present then ignore that element and go to next element in given input array
            // 6. Repeat above steps for all elements in given input array

            //Ex . [5, 4, 100, 1, 200, 2, 101, 3]
            //  |
            //  |   _  _                         _
            //  |  | || |                       | |
            //  | _v_|v_|_______________________v_|____________________
            //       1  2  3  4  5               100   101        200
            
    
            unordered_set <int> S;
    
            //Insert all elements in an array
            for(auto &it: nums)
            {
                S.insert(it);
            }
    
            //vector < vector<int>> Mat;
            int CurrSeq = 0, series, MaxSeq = 1;
            for(int i = 0 ; i < nums.size(); i++)
            {
                //If it doesn't have left neigbor
                if(!S.count(nums[i]-1))
                {
                    //Form vector
                    //vector<int> vec;
    
    
                    series = nums[i];
                    CurrSeq = 0;
    
                    while(S.count(series))
                    {
                        CurrSeq++;
                        series++;
                    }
                
                    MaxSeq = max(MaxSeq,CurrSeq);        
                }
    
                //If It has its left neigbor simply ignore that element and go to next
            }
    
            return MaxSeq;
            
        }
    };