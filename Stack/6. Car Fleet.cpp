class Solution {
    // Que: There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

    // You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

    // A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

    // A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

    // If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

    // Return the number of car fleets that will arrive at the destination.
    
    //Example 1:
    // Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

    // Output: 3

    // Explanation:

    // The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
    // The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
    // The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
    public:
        //comparator function()
        // This function is used for sorting the pair <position, speed>
        // It should sort according to position
        static bool comparator(pair <int, int>& p1, pair <int, int>& p2)
        {
            if(p1.first > p2.first)
                return true;
            else
                return false;
    
        }
    
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            
            //Corner case 1:
            //If there is only one car then the fleet is one
            if(position.size() == 1)
                return 1;
    
            // Algo:
            // 1. Make pair <pos, speed> for binding the position with the speed of car
            // 2. Sort it in decreasing order of position to traverse from the target 
            // 3. start traversing the decreasing order sorted vector 
            // 4. Calculate the time to reach the current car to the target with formula: (target - pos)/speed
            // 5. If the time to reach the current car < that for stack.top, 
            //    that means the current car will eventually collide with stack top and make car fleet 
            //    as the current car is faster than the stack top
            // 6. Such car should be ignored as already covered in a fleet inside the stack 
            // 7. If the time to reach the current car > that for stack.top, 
            //    this is separate car to be considered for fleet so push to the stack
            // 8. Finally with above algo, traverse all the cars 
            // 9. The stack size will denote how many separate car fleets we have all together

            // Time Complexity Analysis:
            // We are traversing the cars array at least once 
            // O(N) where N is the number of cars


            // Space Complexity Analysis
            // We are saving stack and vector of size of N where N is the number of cars
            // So, O(N) where N is the number of cars
            
            vector <pair <int, int>> S;
    
    
            // set<pair<int, int>> S;
    
            for(int i = 0 ; i < position.size() ; i++)
            {
                S.push_back(make_pair(position[i], speed[i]));
            }
            // cout<<"Input vec: "<<endl;
            // for(auto &it : S)
            // {
            //     cout<< " < "<<it.first<<", "<<it.second <<"> ";
            // }
            // cout<<endl;
            sort(S.begin(), S.end(), comparator);
    
            // cout<<"sorted: "<<endl;
            // for(auto &it : S)
            // {
            //     cout<< " < "<<it.first<<", "<<it.second <<"> ";
            // }
            // cout<<endl;
    
            stack <pair<int, int>> Soln;
            
            for(auto iter = S.begin(); iter != S.end(); iter++)
            {
                if(iter == S.begin())
                {
                    Soln.push({iter->first, iter->second});
                    //cout<<"Stack push 1st: ";
                    //cout<< " < "<<Soln.top().first<<", "<<Soln.top().second <<"> ";
                    //cout<<endl;
                    continue;
                }
                float currCarTime = ((float)(target - iter->first)/ iter->second);
                float currFleetTime = ((float)(target - Soln.top().first) / Soln.top().second);
                //cout<< "currCarTime: " << currCarTime << " currFleetTime: " <<currFleetTime<<endl;
                if(currCarTime > currFleetTime)
                {
                    Soln.push({iter->first, iter->second});
                    //cout<<"Stack push: ";
                    //cout<< " < "<<Soln.top().first<<", "<<Soln.top().second <<"> ";
                }
                    

            } 
            return Soln.size();
    
        }
    };