class Solution {
    public:
        int reverse(int x) {
            // Ex:
            // Input: x = 123
            // Output: 321
    
            int digit;
            int res = 0;
    
            while(x)
            {
                // take out last digit
                digit = (x % 10);
                // clip off last digit from x 
                x/=10;
                
                // While adding last digit have some checks for corner cases:
    
                // if res > clipped off last digit of INT_MAX i.e (INT_MAX/10) then return 0
                if(res > (INT_MAX/10))
                    return 0;
    
                // if res == clipped off last digit of INT_MAX i.e (INT_MAX/10)
                // then check for adable digit > than 
                // last digit of INT_MAX which is (INT_MAX%10)
                if((res == (INT_MAX/10)) && digit > (INT_MAX%10)) 
                    return 0;
    
                // if res < clipped off last digit of INT_MIN i.e (INT_MAX/10) then return 0
                if(res < (INT_MIN/10))
                    return 0;
    
                // if res == clipped off last digit of INT_MIN i.e (INT_MIN/10)
                // then check for adable digit < than 
                // last digit of INT_MIN which is (INT_MIN%10)
    
                if((res == (INT_MIN/10)) && digit < (INT_MIN%10)) 
                    return 0;
            
                //add that digit into res by multiplying previous result by 10
                res = (res * 10) + digit;
    
            }
            return res;
            
            
        }
    };