class Solution {
    // Que: Given two strings needle and haystack, 
    // return the index of the first occurrence of needle in haystack, 
    // or -1 if needle is not part of haystack.

    // Input: haystack = "sadbutsad", needle = "sad"
    // Output: 0
    // Explanation: "sad" occurs at index 0 and 6.
    // The first occurrence is at index 0, so we return 0.
    public:
        int strStr(string haystack, string needle) {
            
            // if(haystack.find(needle) != string::npos)
            //     return haystack.find(needle);
            // else
            //     return -1;
    
            int l1 = haystack.length();
            int l2 = needle.length();
            
            if(l2 > l1)
                return -1;
            
            for(int i = 0 ; i <= l1-l2 ; i++)
            {
                //if the first character matches then go traversing next set of needle
                if(haystack[i] == needle[0])
                {
                    bool check = true;
                    for(int j = 1 ; j < l2 ; j++)
                    {
                        // at any point mismatch happens
                        // leave j loop then and there 
                        //then can move to the very next character stating from i++ of above for loop
                        if(haystack[i+j] != needle[j])
                        {
                            check = false;
                            break;
                        }
                    }
                    if(check) return i;
                }
            }
            //return -1;
            return -1;
        }
    };