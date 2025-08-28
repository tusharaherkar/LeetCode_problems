class Solution {
    // Que:
    // Evaluate the expression. Return an integer that represents the value of the expression.

    // Note that:

    // The valid operators are '+', '-', '*', and '/'.
    // Each operand may be an integer or another expression.
    // The division between two integers always truncates toward zero.
    // There will not be any division by zero.
    // The input represents a valid arithmetic expression in a reverse polish notation.
    // The answer and all the intermediate calculations can be represented in a 32-bit integer.
    public:
        int evalRPN(vector<string>& tokens) {

            //Algo:
            // 1. declare stack of int 
            // 2. keep on pushing the int encountered while traversing the array
            // 3. If we encounter any of operator
            // 4. then pop b and pop a then perform a (operator) b and push ans again back to stack
            // 5. Keep on doing same 
            // 6. pop last element and return that as that will be the ans of whole RPN - Reversed Polished Notation
    
            stack <int> s;
            int a, b, ans = 0;
    
            for(auto &token : tokens)
            {
    
                if(token != "+" && token != "-" && token != "*" && token != "/")
                {
                    int a = stoi(token);
                    //cout<< " " << a; 
                    s.push(a);
                }
                else
                {
                    
                    {
                        if(token == "+")
                        {
                            b = s.top();
                            s.pop();
                            a =  s.top();
                            s.pop();
                            ans = (a + b);
                            s.push(ans);
                            
                        }
                        else if(token == "-")
                        {
                            b = s.top();
                            s.pop();
                            a =  s.top();
                            s.pop();
                            ans = (a - b);
                            s.push(ans);
                        }
                        else if(token == "*")
                        {
                            b = s.top();
                            s.pop();
                            a =  s.top();
                            s.pop();
                            ans = (a * b);
                            s.push(ans);
                        }    
                        
                        else if(token == "/")
                        {
                            b = s.top();
                            s.pop();
                            a =  s.top();
                            s.pop();
                            ans = (a / b);
                            s.push(ans);
                        }
                    }
                }
            }
            ans = s.top();
            s.pop();
            //delete s;
            return ans;
            
            
        }
    };