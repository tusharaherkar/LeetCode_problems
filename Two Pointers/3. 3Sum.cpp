class Solution {
    //Que: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    //Notice that the solution set must not contain duplicate triplets.

    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // Ex: nums = [-1,0,1,2,-1,-4]
            // This problem is similar to 2 sum with one extra condition
            
            // Algo:
            // First sort the given input array
            // Lets consider a, b and c as triplet
            // traverse each element and consider current element as a
            // For b and c use 2sum  problem's Soln i.e. L & R pointer - refer 2. Two Sum II - Input Array Is Sorted.cpp
            
            // Time Complexity Analysis:
            // traversing whole input array for selecting 'a' will take O(N)
            // selecting proper b & c will take another O(N)
            // so for each a we have to check b & c
            // So, overall, O(N ^ 2) 

            // Space Complexity Analysis
            // No extra space so O(1) = constant space
    
            vector<vector<int>> soln;
            sort(nums.begin(), nums.end());
    
            for(auto &it: nums)
            {
                cout<<" "<< it ;
            }
            cout<<endl;
            int a, b, c;
    
            
    
            for(int i = 0 ; i <nums.size()-2; i++)
            {
                //select a 
                a = nums[i];
    
                //check if it is not same a
                if(i != 0 && a == nums[i-1])
                    continue;
                
                //cout<<"Selected a: "<< a << endl;
    
                int L = i+1;
                int R = nums.size()-1;
    
                while(L < R)
                {
                    //check if it is not same b
                    // nums[L] should not compare between b and a so L != i+1
                    if(L != i+1 &&  nums[L] == nums[L-1])
                    {
                        L++;
                        continue;
                    }    
                    
                    //check if it is not same c
                    if(R != nums.size()-1 &&  nums[R] == nums[R+1])
                    {
                        R--;
                        continue;    
                    }    
                    // Check if it is valid triplet
                    if(a + nums[L] + nums[R] == 0)
                    {
                        vector <int> triplet;
                        triplet.push_back(a);
                        triplet.push_back(nums[L]);
                        triplet.push_back(nums[R]);
                        soln.push_back(triplet);
                        //cout<<"found triplet: "<< a <<", "<<nums[L] <<", "<<nums[R]<<endl;
                        L++; R--;
    
                    }
                    // a is common for all b & c
                    // if a + nums[L] + nums[R] < 0
                    // we need to maximize down the nums[L] + nums[R] so L++
                    else if(-a > (nums[L] + nums[R]))
                    {
                        L++;
                    }
                    // if a + nums[L] + nums[R] > 0
                    // we need to lower down the nums[L] + nums[R] so R--
                    else
                    {
                        R--;
                    }
                }
            }
            //return Soln;
            return soln;
    
        
            
        }
    };