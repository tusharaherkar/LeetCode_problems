class Solution {
    public:
        double  Pow(double x, long n){
            if(n == 0)
                return 1;
            
            if(n == 1)
                return x;
            
            double res = Pow(x*x, n/2);
            
            return (n%2 ? x*res : res);
        }
        double myPow(double x, int n) {
    
            // Corner case 1: 0 ^ any number is 0
            if(x == 0)
                return 0;
            
            // Corner case 2: any number ^ 1 is that number itself
            if(n == 1)
                return x;
            
            // Algo:
            // 1. Ex. x = 2 and n = 4 i.e (2 ^ 4 )
            //    (2 ^ 2)     *             (2 ^ 2)
            //     /    / 
            // (2 ^ 1)*(2 ^ 1) -> whatever comes here has to be multiplied to itself   
            // So Pow() function does same
            // but if the power is odd then one extra x needs to be multiplied
    
            // Time Complexity Analysis:
            // Each step is divided into half
            // So O(log N) where n is the power
    
            // Space Complexity Analysis
            // recurssion is used so recurrsion stack will take O(logN)
            
    
    
            double res = Pow(x,abs(static_cast<long>(n)));
    
            return (n < 0 ? (1/res) : res);
            
            
        }
    };