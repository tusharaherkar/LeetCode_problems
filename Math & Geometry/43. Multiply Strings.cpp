class Solution {
    // Que: Given two non-negative integers num1 and num2 represented as strings, 
    // return the product of num1 and num2, also represented as a string.

    // Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
    // Example 1:

    // Input: num1 = "2", num2 = "3"
    // Output: "6"
public:
    string multiply(string num1, string num2) {


        // Corner Case 1 : if num1 is 0
        if(num1.length() == 1 && num1[0] - '0' == 0)
            return "0";
        
        // Corner Case 2: if nume 2 is 0
        if(num2.length() == 1 && num2[0] - '0' == 0)
            return "0";
        
        // Algo:
        // 1. Reverse both the nums as nums1[0] and nums2[0] will be MSB and we need to iterate from LSB
        // 2. Lets assume nums2 will be always less number of digit hence if the nums2 length is more then swap nums1 and nums2 
        //    to keep the terminologies same
        // 3. Declare ansVec of char which will hold multiplication of num1 and num2 intialize with all 0s
        //    The max size of ansVec will be M + N where M is the length of num1 and N is the length of nums2.
        //    as ansVec will hold the multiplication in reverse order
        // 4. Start from LSB of nums2 
        // 5. multiply digit by digit and keep it in ansVec
        //    Ex 9 * 9 will be 81 so 1 will be kept at position i+j and 8 will propogated and added to the i+j+1 th position
        // 6. Likewise, mdultiply all digits of num2 with num1
        // 7. Delete all trailing 0s as ansVec keeps multiplication in reverse order.
        // 8. Form the string ans with the help of ansVec and return the same ans string

        // Time Complexity Analysis:
        // O(M * N) where M is the length of num1 and N is the length of nums2

        // Space Complexity Analysis
        // We have used ansVec of size M + N
        // Hence, O(M + N) where M is the length of num1 and N is the length of nums2

        
        // Declare ansVec of char which will hold multiplication of num1 and num2 intialize with all 0s
        //    The max size of ansVec will be M + N where M is the length of num1 and N is the length of nums2.
        //    as ansVec will hold the multiplication in reverse order
        vector<char> ansVec(num1.length()+num2.length(), '0');

        // Reverse both the nums as nums1[0] and nums2[0] will be MSB and we need to iterate from LSB
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // Lets assume nums2 will be always less number of digit hence if the nums2 length is more then swap nums1 and nums2 
        //    to keep the terminologies same
        if(num1.length() < num2.length())
            swap(num1, num2);


        // Start from LSB of nums2 
        for(int i = 0 ; i < num2.length(); i++)
        {
            for(int j = 0 ; j < num1.length(); j++)
            {
                // multiply digit by digit 
                //    Ex 9 * 9 will be 81 so 1 will be kept at position i+j and 8 will propogated and added to the i+j+1 th position    
                int digitMultiply = (((num2[i] - '0') * (num1[j] - '0')) +  (ansVec[i+j] -'0')) ;

                // Get the LSB of digitMultiply by % 10 
                ansVec[i+j] = (digitMultiply%10 + '0');
                
                // Get the MSB of digitMultiply by divide by 10 
                // Carry the later digit to the next place and add to the exisiting digit which is present there
                ansVec[i+j+1] = ((ansVec[i+j+1] - '0') + (digitMultiply/10)) + '0';
            }
        }
        
        // Delete all trailing 0s as ansVec keeps multiplication in reverse order.
        for(int i = ansVec.size()-1 ; i >=0 ; i--)
        {
            if(ansVec[i] != '0')
                break;
            
            ansVec.pop_back();
        }

        //ansVec keeps multiplication in reverse order.
        reverse(ansVec.begin(), ansVec.end());

        // Form the string ans with the help of ansVec and return the same ans string
        string ans;
        for(int i = 0 ; i < ansVec.size(); i++)
            ans+=ansVec[i];
        return ans;        
    }
};