class Solution {
    public:
        int getSum(int a, int b) {
            // getSum
            // Algo:
            // Carry will be propagated wherever it occurs
            // Hence, need to loop in do while 
            // while (b) will not help if the b input is 0 then it will not enter the loop
            // This logic is coming from adder implementation in Digital electronics
    
            int res = 0;
            do
            {
                // a ^ b will store the addition
                res = a ^ b; 
                // carry needs to be propagated to left hand side by 1 bit hence below step required
                b = ((a & b) << 1);
                //a should store result 
                a = res;
    
                //and we have to keep on performing above steps till carry is not present for propagating to left side 
                
            }while(b);
            return res;
    
    
    
        }
        
    };