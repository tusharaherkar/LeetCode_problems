class Solution {
    //Que:  A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    // Given a string s, return true if it is a palindrome, or false otherwise.
    public:
        bool isPalindrome(string s) {
            // Ex: s = "A man, a plan, a canal: Panama" return true 
            // Input: s = "A man, a plan, a canal: Panama"
            // Output: true
            // Explanation: "amanaplanacanalpanama" is a palindrome.

            // Algo:
            // 1. First get the simplified string by removing whitespaces, commas, colons etc
            // 2. Take L = 0 and R = length of simplified string -1
            // 3. with this two pointers we should come till half of simplified string and return true if all the chars of simplified[L] == simplified[R]
            // 4. Inc L and dec R i.e. L++ and R--
            // 5. at any point simplified[L] != simplified[R] then return false.

            // Time Complexity Analysis:
            // O(N) to form the simplified string
            // O(N/2) due to two pointers but ~= O(N) where N is length of string
            
            // Space Complexity Analysis
            // O(N) where N is the length of string
            

            string simplified ;
            
            // 1. First get the simplified string by removing whitespaces, commas, colons etc
            for(int i = 0 ; i < s.length() ; i++)
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                {
    
                    simplified += 'a' + s[i] - 'A';
                }   
                else if(s[i] >= 'a' && s[i] <= 'z')
                {
                    simplified += s[i];
                }
                else if(s[i] >= '0' && s[i] <= '9')
                {
                    simplified += s[i];
                }
            
            }
            //Corner case 2: if simplified.length() == 0
            //cout << "simp: "<< simplified <<endl;
            if(simplified.length() == 0)
            {
                return true;
            }
            //Check for pallindrome
            for(int i = 0, z =  simplified.length()-1; i < simplified.length()/2 ; i++, z--)
            {
                if(simplified[i] != simplified[z])
                    return false;
            }
            
            return true;
        }
    };