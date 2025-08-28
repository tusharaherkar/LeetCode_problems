class Solution {
public:
    vector<int> twoSum_AnotherApproach(vector <int> &nums, int target)
    {
        // Algo 2: (using Sliding Window)
        //1. Declare vector <pair<int, int>> to store the elements and their positions in the form of pairs
        //2. Sort the array
        //3. L = 0 and R = nums.size-1
        //4. if nums[L] + nums[R] == target return the result 
        //5. if nums[L] + nums[R] < target then Increment L 
        //6. if nums[L] + nums[R] > target then Decrement R
        //7. Loop till L<R

        vector <pair<int, int>> pos;
        for(int i = 0 ; i < nums.size(); i++)
        {
            pos.push_back({nums[i], i});
        }

        sort(pos.begin(), pos.end());

        int L = 0;
        int R = nums.size()-1;
        vector <int> res;

        while(L < R)
        {
            if(pos[L].first + pos[R].first == target)
            {
                //return the res if found with the positions pushed 
                res.push_back(pos[L].second);
                res.push_back(pos[R].second);
                return res;
            }

            if(pos[L].first + pos[R].first < target)
                L++;
            else
                R--;
        }
        return res;

        // Time Complexity Analysis:
        // 1. Worst case we have to traverse each element atleast once here O(N)
        // 2. vector <pair<int, int>> is getting sorted which would take O(NlogN)
        // So, O(N) + O(NlogN) = O(NlogN) 

        // Space Complexity Analysis:
        // 1. Extra space of vector <pair<int, int>> is required 
        //    to store the element and its position here O(N)
        // 2. result is stored in vector of constant space 2
        // So, O(N) where N is the given number of elements in array
         
    }
    vector<int> twoSum(vector<int>& nums, int target) {

        //There are two approaches to solve the problem
        // 1. Two Sum by using vector: twoSum_AnotherApproach(Sliding Window Approach) 
        // 2. Two Sum by using Map
        return twoSum_AnotherApproach(nums, target);

        //The below one is two sum by using MAP

        // Algo 1:
        // 1. Declare unordered_map <int, int> to store nums[i] and its corresponding pos
        // 2. Store elements of nums as keys and positions of nums[i] as values in unordered_map by traversing the nums
        // 3. Again start traversing in map from start as (auto &currElement: unordered_map)
        // 4. check (target - currElement) present in map or not
        // 5. if present the return its position
        // 6. if not go to next element
        // 7. Think: Can we do above algo while traversing the elements while storing it? - still the worst time complexity is same

        // Time Complexity Analysis:
        // Worst case it takes O(N) to traverse all the elements of nums
        // So, O(N) where N is the number of elements in given input

        // Space Complexity Analysis
        // Extra space of nums and pos is stored in map
        // So, O(N) where N is the number of elements in given input

        int L = 0, R = 0, currSum;
        // soln is for storing the result
        vector <int> soln; 
        // Declare unordered_map <int, int> to store nums[i] and its corresponding pos
        unordered_map <int, int> map;

        // Traverse the given array with L 
        for(L = 0 ; L < nums.size(); L++)
        {
            //Check while traversing target - nums[L] present or not
            // If yes we got the soln
            if(map.find(target - nums[L]) != map.end())
            {
                // If found store result/soln and immediatrly return as the soln is unique
                soln.push_back(L);
                auto it = map.find(target - nums[L]);

                soln.push_back(it->second);
                return soln;

            }
            //If not store the element and its position in map
            map[nums[L]] = L;

        }
        //just to resolve the compilation issue
        //problem says that every problem will have unique soln
        // control flow should not come here
        return soln;
    }
};