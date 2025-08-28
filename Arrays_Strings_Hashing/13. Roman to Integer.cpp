class Solution {
public:
    int romanToInt(string s) {


        unordered_map <char, int> RomanValMap;
        
        // Make the Symbol and Value table in RomanValMap
        RomanValMap['M'] = 1000;
        RomanValMap['D'] = 500;
        RomanValMap['C'] = 100;
        RomanValMap['L'] = 50;
        RomanValMap['X'] = 10;
        RomanValMap['V'] = 5;
        RomanValMap['I'] = 1;

        // Intution:
        // Traverse two two characters at a time
        //  X I V
        //  |_| |
        //    |_|
        // First visit XI and then inc traversal by one and visit IV
        // If the characters are in non-increasing order then simply add the current weight of roman in currSum
        // If they are in increasing order then subtract current weight of roman in currSum
        // If traversal has reached the last char in given string simply add its weight

        // Time Complexity Analysis:
        // Traverse the entire string s once
        // O(s.length()) 

        // Space Complexity Analysis
        // O(1) = constant space
        // No extra space required

        // corner case 1: if only single char
        if(s.length() == 1)
        {
            return RomanValMap[s[0]];
        }
        
        //
        int traversal = 0;
        int currSum = 0;

        // make traversal to go throgh entire string from left to right-2 as 
        // we are looking 2-2 characters at a time
        while(traversal < s.length()-1)
        {
            // If the characters are in non-increasing order then simply add the current weight of roman in currSum
            if(RomanValMap[s[traversal]] >= RomanValMap[s[traversal+1]])
            {
                currSum += RomanValMap[s[traversal]];
            }
            // If they are in increasing order then subtract current weight of roman in currSum
            else
            {
                currSum -= RomanValMap[s[traversal]];
            }
            
            traversal++;
        }

        // If traversal has reached the last char in given string simply add its weight    
        // we can not club this condition in above loop as the above loop is looking for s[traversal+1] which is array out of bound access error
        if(traversal == s.length()-1)
            currSum += RomanValMap[s[traversal]];

        return currSum;
        
    }
};