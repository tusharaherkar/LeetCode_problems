class Solution {
public:
    bool isSubsequenceOptimized(string s, string t) {

        int sPointer = 0;  // used to traverse the string s
        int tPointer = 0 ; // used to traverse the string t

        // Algo 2 (Two pointer Approach):
        // 1. Set the sPointer and tPointer to 0
        // 2. traverse string s and t one by one
        // 3. Inc sPointer if s[sPointer] matches with t[tPointer]
        // 4. Inc tPointer by default as we need to match s[sPointer] always
        // 5. loop till (sPointer < s.length() && tPointer < t.length())
        
        // Time Complexity Analysis:
        // O(t.length()) worst case we need to traverse entire t string

        // Space Complexity Analysis
        // O(1) = constant space

        while(sPointer < s.length() && tPointer < t.length())
        {
            if (s[sPointer] == t[tPointer])
            {
                sPointer++;
            }
            tPointer++;
        }
        return (sPointer == s.length());

    }
    bool isSubsequence(string s, string t) {
        // Corner Case 1:
        if (s.length() > t.length())
            return false;

        return isSubsequenceOptimized(s, t);

        // Algo 1 (Brute force Approach):
        // 1. Declare R = 0;
        // 2. find s[R] in t.find() and get the position 'pos'
        // 3. clip off initial part till pos and form new t
        // 4. Inc R 
        // 5. loop till R < s.length() and t is not vanished completely
        // 6. if there are still some of s[R] left to check in t then clearly return false
        // 7. else return true

        // Time Complexity Analysis:
        // O(M * N) where M is the length of s and N is the length of t
        // as for each char in s we need to traverse t

        // Space Complexity Analysis
        // O(1) = constant space

        
        int R = 0;

        while(R < s.length() && t.length() != 0)
        {
            int pos = t.find(s[R]);
            
            if(pos == string :: npos)
            {
                return false;
            }
            else
            {
                t = t.substr(pos+1, (t.length()-pos-1));
                //cout<< " R: "<< R << " "<< t<<endl;                 
                
            }
            R++;
        }
        return (R < s.length() ? false : true);
        
    }
};