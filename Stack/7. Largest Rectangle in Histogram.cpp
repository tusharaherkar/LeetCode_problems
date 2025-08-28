class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
              if(heights.size() == 1)
                return heights[0];
    
            //Algo/ Intutions:
            // 1. if the visited nodes are [1, 2, 3, 4, 2]
            //                                          ^        
            //                                          |
            //                                      curr Element
            //  
            // when visiting nodes from left to right first element is 1
            // when we visit 2 we understood that 1 can be extended to histogram 2 
            // and total rectangle area which will form is curr index (1-0)*1 = 1 
            // that is nothing but 1 can be extended further if we encounter 2
            // So push 1 and 2 on to the stack along with their position which will help 
            // in calculating the max Area
            // So likewise till we go last element 2 the stack will look like below
            //
            // _________________
            //| heights|   pos  |
            //|________|________|
            //|        |        |
            //|        |        |
            //|   4    |    3   | <-- top
            //|   3    |    2   |
            //|   2    |    1   |
            //|   1    |    0   |
            //|________|________|
            // Now we encounter last element 2
            // so now if we see top of stack which is 4 can not be extended as we encounter 2
            // so pop that and check the area = (curr index - top.pos) * heights of top of stack
            // in this cane (4-3) * 4 = 4
            // Keep track of maxArea of historgram = 4
            // now due to height [curr index] the next stack top which is {3, 2} also can not be able to extend
            // so pop it and calculate area (4-2)*3 = 6
            // Keep track of maxArea of historgram = 6
            // next one is {2 , 1} which matches with heights[current index]
            // So no need to do anything as the previous 2 can be extended simply go to next element i.e. curr index++
            // check code for further details
        
            
    
            stack <pair < int, int> > s;
            int maxArea=heights[0];
    
            s.push({0, heights[0]});
            int i = 0;
            
            for(i = 1 ; i < heights.size() ; i++)
            {
                //If the currheight is equal to stack top no need to push or do anything
                if(heights[i] == s.top().second)
                {
                    continue;
                    //do nothing
    
                } 
                //if the current height is less than stack top height
                //means the stack top height can not be extended further
                else if(heights[i] < s.top().second)
                {
                    int lastPoppedIndex = 0;
                    //so, need to pop all the heights till height is not less than top
                    //compute the areas and update max area accordingly
                    while(!s.empty() && heights[i] < s.top().second)
                    {
                        lastPoppedIndex = s.top().first;
                        int currArea = (i - lastPoppedIndex) *  s.top().second;
                        //update the maxArea if needed
                        maxArea = max(maxArea, currArea);
                        //pop the element from top
                        s.pop();
                    }
                    // lastPoppedIndex is pushed with height of curr index - why?
                    // because check picture example [1, 5, 6, 2]
                    // because of 2 we bound to pop 5 & 6 but 5 is the last element popped
                    // if you carefully observe we need to push 2 
                    // but think like 2 could be extended to left hand side till the index of 5
                    // so why can't we push 2 with index of 5                 
                    s.push({lastPoppedIndex, heights[i]});
    
                }
                //if the current height is greater than s.top 
                //then stack top can be extended so no need to touch top
                //current height can also be extended hence simply push to the stack
                else
                {
                    s.push({i, heights[i]});
                }
                    
            }
    
            //If stack is not empty then there are some area computations left
            while(!s.empty())
            {
                int currArea = (i - s.top().first) *  s.top().second;
                maxArea = max(maxArea, currArea);
                s.pop();
            }
            return maxArea;
            
        }
    };