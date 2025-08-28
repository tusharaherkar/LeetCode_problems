class Solution {
public:
    bool isAnagram(string s, string t) {

        //Algo 1:
        // 1. s & t are not valid anagrams if the lengths are not equal
        // 2. if the lengths are queal then there is a chance that both can/may be anagrams
        // 3. Sort s & t and check if each char of s is same as that of t
        // 4. if not at any given point of time then both are not valid anagrams
        
        // Time Complexity Analysis:
        // sorting s and t takes O(nlogn) time where n is the length of s & t if macthes
        // Traversing will take O(n)
        // So, O(n) + O(nlogn) = O(nlogn)

        // Space Complexity Analysis
        // No extra space is used so O(1) = constant space

        //Algo 2 (Uses Extra Constant Space):
        // 1. Declare the unordered_map <char, int> to check the frequency of each char of s & t
        // 2. freq of each char in s should match to frequency of each char in t
        // 3. return false if there is any mismatch occured
        // 4. We can use array of 200 in place of map to store the freq

        
        // Time Complexity Analysis:
        // Traverse s & t takes O(n) where n is the length of s & t if matches
        // Each char of s & t has to be traversed atleast once to get the freq
        // character matching algo would take constant time as we have max 200 ascii characters to check
        // So overall O(n) + O(1) = O(n)

        // Space Complexity Analysis
        // array of 200 will take constant space of 200
        // Hence, O(1) = constant space


        // Check the necessary condition first
        // s & t are not valid anagrams if the lengths are not equal
        if(s.length() != t.length())
            return false;
        
        int res = 0, i =0;

        //sort string s
        sort(s.begin(), s.end());
        //sort string t
        sort(t.begin(), t.end());

        //Traverse s & t togetherly
        for(i = 0 ; i < s.length() ; i++)
        {
            //If there is any deviation between s & t 
            //then it no longer considered to be valid anagrams
            if (s[i] != t[i])
                return false;

        }
         
        //if all are equal then return those as valid anagrams
        return true;
        
    }
};