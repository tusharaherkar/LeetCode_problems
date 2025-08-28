class Solution {
    public:
        bool isValid(string s) {

            // Algo:
            // 1. Traverse the given array one by one
            // 1. push any type of opening braces into the stack
            // 2. Whenever closing braces visited while traversing check the stack top 
            //    If the stack is not empty and top is its corresponding opening braces 
            //    then pop the stack
            // 3. At the end the stack should be empty if all the pranthesis matched here return true
            // 4. If the stack has some elements then return false meaning parenthesis not matched

    
            stack <char> st;
    
            //Traverse the input string
            for(int i = 0 ; i < s.length() ; i++)
            {
                switch(s[i])
                {
                    case '(':
                    case '[':
                    case '{':
                        st.push(s[i]);
                        break;
                    case ')':
                        //cout<<"st.top(): "<<st.top()<<endl;
                        if(st.empty() || st.top() != '(')
                            return false;
                        else
                            st.pop();
                        break;
    
                    case '}':
                        //cout<<"st.top(): "<<st.top()<<endl;
                        if(st.empty() || st.top() != '{')
                            return false;
                        else
                            st.pop();
                        break;
                    case ']':
                        //cout<<"st.top(): "<<st.top()<<endl;
                        if(st.empty() || st.top() != '[')
                            return false;
                        else
                            st.pop();
                        break;
                        
                    default:
                        cout<<"should not come here!" <<endl;
                        break;
                }    
            }
            if(!st.empty())
                return false;
            else
                return true;
            
            return true;
        }
    };