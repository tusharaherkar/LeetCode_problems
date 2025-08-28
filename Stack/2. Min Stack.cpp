class MinStack {
    // Que: Implement the MinStack class:

    // MinStack() initializes the stack object.
    // void push(int val) pushes the element val onto the stack.
    // void pop() removes the element on the top of the stack.
    // int top() gets the top element of the stack.
    // int getMin() retrieves the minimum element in the stack.
    // You must implement a solution with O(1) time complexity for each function.
    public:
        // Algo:
        // Ex: following operations are performed as a example
        // push : -2, 0, -3
        // getMin() - return -3
        // pop()    - erase -3 and -3
        // top()    - return 0
        // getMin() - return -2
        // 
        //  _________________
	    //  | values |   Min  |
	    //  |________|________|
	    //  |        |        |
	    //  |        |        |
	    //  |        |        |
	    //  |   -3   |   -3   |
	    //  |   0    |   -2   |
	    //  |   -2   |   -2   |
	    //  |________|________|

        // Algo/ Intution:
        // Maintain vector<vector <int>> which will behave as minstack
        // 1. declare vector <vector<int> > and currMin - will give minimum value at that point of time
        // 2. MinStack() will initialize currMin as INT_MAX
        // 3. push(int Elem) - if pushed value is < currMin then update currMin and push it along with Elem
        //                     Otherwise push previous {Elem, currMin}
        // 4. pop() - will pop last inserted pair of {Elem , Min} from top of stack
        //            after popping update the currMin with getMin()
        //             because the currMin might have been popped out
        // 5. top() - will give st[st.size()-1][0] and return -1 if stack is empty()
        // 6. getMin() - will give st[st.size()-1][1] and return -1 if stack is empty()

        // Time Complexity Analysis:
        // All functions will be O(1) - constant time

        // Space Complexity Analysis
        // We have taken extra space of O(N)


        vector <vector<int> > st;
        int currmin;
        MinStack() {
            currmin = INT_MAX;    
        }
        
        void push(int val) {
            
            if(val < currmin)
                currmin = val;
    
            if(st.size() == 0)
            {
                currmin = val;
            }
    
            vector<int> v1;
            v1.push_back(val);
            v1.push_back(currmin);
            st.push_back(v1);
        }
        
        void pop() {
            if(st.size() > 0)
                st.pop_back();
            
            currmin = getMin();
        }
        
        int top() {
            int topvalue = -1;
            if(st.size() > 0)
            {
                topvalue = st[st.size() - 1][0];
            }
            return topvalue;
        }
        
        int getMin() {
            int minValue = -1;
            if(st.size() > 0)
            {
                minValue = st[st.size() - 1][1];
            }
            return minValue;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */