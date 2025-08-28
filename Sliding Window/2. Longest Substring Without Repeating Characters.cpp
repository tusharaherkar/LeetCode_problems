class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
    
            // Corner case 1:
            // If the input string length is 0 or 1 
            // then length itself will be longest substring
            if(s.length() == 0 || s.length() == 1)
                return s.length();
            
            // Corner Case 2:
            // If the length is 2 then direct compare the s[0] and s[1]
            if(s.length() == 2)
            {
                return ((s[0] != s[1]) ? 2 : 1);   
            }
               
            //Initialize both right and left pointer to 0
            int L = 0 ;
            int R = 0;
            int count = (R-L+1);
            int LongestSubstr = 1;
    
            // Algo / Intution:
            // 1. Traverse whole string using R pointer
            // 2. Insert elements in set if no repeatation seen (use set for checking repeatation)
            // 3. Calculate the count of nonrepeated character and maintain longest length
            // 4. If repeatation seen, remove the elements from L pointer unless current repeated element gone from the set 
            // 5. then insert the current element into set to check whether the current element occurs to be repeated in the future  
            // 6. Recalculate the count of nonrepeated character and maintain longest length
            // 7. Return longestLength from the function 

            // Time Complexity Analysis:
            // O(N) where N is the number of chars in the string

            // Space Complexity Analysis
            // set is used 
            // O(N)

            set <char> S;
    
            while(R < s.length())
            {     
                while(S.count(s[R]))
                {
                    S.erase(s[L]);
                    L++;
                }
                S.insert(s[R]);
                count = (R-L+1);
                LongestSubstr = max(LongestSubstr, count);
                R++;
            }
            return LongestSubstr;
        }
    };