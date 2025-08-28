class Solution {
public:
    bool isHappy(int n) {
        int current = n, sumOfSquares;
        // Intution:
        // The only numbers who are single digit i.e. < 9 which are happy 
        // ---> 1 and 7
        // compute all values in the as per given condition till it deduce down to single digit
        // When it deduce down to single digit check the deduced value is 
        // 1 OR 7 if yes then it is Happy number otherwise not

        // Algo:
        // 1. set current same as given input
        // 2. Compute sumOfSquares of each digit in current
        // 3. overwrite current with sumOfSquares 
        // 4. compute sumOfSquares till it becomes single digit

        // Time Complexity Analysis:
        // O(logN) as max computation calls for sumOfSquares happens for logN times

        // Space Complexity Analysis
        // O(1) as constant space is used  
        
        while (current > 9) { 
            sumOfSquares = 0;
            while (current > 0) {
                sumOfSquares += (current % 10) * (current % 10);
                current /= 10; 
            }
            current = sumOfSquares;
        }
        return (current == 1 || current == 7); 
        
    }
};