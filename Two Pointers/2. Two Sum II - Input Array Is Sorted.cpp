class Solution {
    // Que: Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    //Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {

            // Algo:
            // 1. The given input array is already sorted
            // 2. Take L = 0 and R = last element of numbers
            // 3. if addition of numbers[L] & numbers[R] > target then addition is getting more than target
            //    In such case we need to bring the addition down for that purpose greater number should bring down so R-- 
            // 4. If addition of numbers[L] & numbers[R] > target, we need to inc addition meaning smaller numer should be increased so L++
            // 5. Return the pair numbers[L] and numbers[R] if == target

            // Time Complexity Analysis:
            // O(N) as worst case we can get that pair in the middle 
            // So worst case O(N) where N is the number of elements in given input array i.e. numbers

            // Space Complexity Analysis
            // O(1) no extra space needed
            
            // Take L = 0 and R = last element of numbers
            int L = 0 , R = numbers.size()-1;
            vector <int> soln;
            while(L < R)
            {
                // Return the pair numbers[L] and numbers[R] if == target   
                if(numbers[L] + numbers[R] == target)
                {
                    soln.push_back(L+1);
                    soln.push_back(R+1);
                    return soln;
    
                }
                //if addition of numbers[L] & numbers[R] > target then addition is getting more than target
                //    In such case we need to bring the addition down for that purpose greater number should bring down so R-- 
                else if(numbers[L] + numbers[R] > target)
                {
                    R--;
                }
                // If addition of numbers[L] & numbers[R] > target, we need to inc addition meaning smaller numer should be increased so L++
                else
                    L++;
            }
            return soln;
        }
    };