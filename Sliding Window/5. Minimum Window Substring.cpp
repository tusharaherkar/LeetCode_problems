class Solution {
    // Que: Given two strings s and t of lengths m and n respectively,
    // return the minimum window substring of s such that every character in t 
    // (including duplicates) is included in the window. If there is no such substring,
    // return the empty string "".

    public:
        string minWindow(string s, string t) {
    
            // Example :
            // Input: s = "ADOBECODEBANC", t = "ABC"
            // Output: "BANC"
            // Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
            //Corner Case 1:
            if(t.length() > s.length())
                return "";

            //Check the freqs of each of the characters from string t
            unordered_map <int, int> t_freq;
            unordered_map <int, int> s_freq;
    
            for (auto &it : t)
            {
                t_freq[it]++;
            }
    
            int R = 0;
            int L = 0;
            
            pair <int, int> res;
            int reslen = INT_MAX;
            int have = 0;
            int need = t_freq.size();
    
            while(R < s.length())
            {
                //if the element exists in t then only inc freq of s of that char by 1
                if(t_freq[s[R]])
                {
                    s_freq[s[R]]++;
    
                    //Now check if the freq of character which we have inc 
                    // has become equal to the freq in t_freq 
                    // If yes then inc have
                    if(s_freq[s[R]] == t_freq[s[R]])
                        have++;
    
                    // if have and need are same then try to shrink the window
                    // calculate each time and maintain smaller length window
                    while(have == need)
                    {
                        if(R-L+1 < reslen)
                        {
                            res = {L, R};
                            reslen = min(R-L+1, reslen);
                        }
    
                        if(s_freq.count(s[L]))
                        {
                            //dec element from s freq before inc L
                            s_freq[s[L]]--;
                            
                            //after dec update the have variable if needed
                            if(s_freq[s[L]] < t_freq[s[L]])
                                have--;    
                        }
                        
                        L++;
                    }
                }   
                //Now check whether the freq 
                R++;
            }
            //check if reslen has changed or not
            //If changed that means we have minimum window found
            // If reslen is still INT_MAX means have has never become till need
            return (reslen == INT_MAX ? "" : s.substr(res.first, reslen));
    
            
        }
    };