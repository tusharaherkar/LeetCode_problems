class Solution {
    // Que: Given an array of integers temperatures represents the daily temperatures, 
    // return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
    // If there is no future day for which this is possible, keep answer[i] == 0 instead.

    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            
            // Corner case 1:
            if(temperatures.size() == 1)
            {
                vector<int> ans(1, 0);
                return ans;
            }
            // Ex:
            // Input: temperatures = [73,74,75,71,69,72,76,73]
            // Output: [1,1,4,2,1,1,0,0]
            
            // Algo:
            // Algo and implementation is slightly different
            // 1. declare stack <pair<int, int>> for temp and its corresponding pos
            // 2. Traverse all day temperatures one by one
            // 3. if stack is empty push {curr temp, pos} into the stack
            // 4. if stack is not empty and curr temp >= stack.top temp then write curr temp 
            //    as warmer day for all those where curr temp >= stack.top
            // 5. Once done push {curr temp, pos} into the stack
            // 6. Once all traversing done, check if stack is not empty if not empty
            //    write 0 for all those positions which are their in stack
            // 
            // Time Complexity Analysis:
            // O(N)

            // Space Complexity Analysis
            // Extra space of stack is used
            // O(N) where N is the size of temperatures array
            

            stack <int> DayTemp;
            stack <int> pos;
            vector<int> ans(temperatures.size(), 0);
    
            for(int i = 0 ; i < temperatures.size() ; i++)
            {
            
                
                while(!DayTemp.empty() && temperatures[i] > DayTemp.top())
                {
                    DayTemp.pop();
                    ans[pos.top()] = i - pos.top();
                    pos.pop();
                }
                if(DayTemp.empty() || (!DayTemp.empty() && temperatures[i] <= DayTemp.top()))
                {
                    DayTemp.push(temperatures[i]);
                    pos.push(i);
                    
                }
            }
            
            return ans;
            
            
        }
    };