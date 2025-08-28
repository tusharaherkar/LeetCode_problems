class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            // first get the minimum string out of given strs
    
            // 
            int minlen = INT_MAX;
            int minIndex = 0;
            for(int i = 0 ; i < strs.size() ; i++)
            {
                if(minlen > strs[i].length())
                {
                    minlen = strs[i].length();
                    minIndex = i;
    
                }
            }
            // once we get the minIndex
            // consider that as longest common prefixed string and decrement 
            // if that much length is not present
            bool found = false;
            string subS;
            for(int i = minlen-1 ; i >= 0 ; i--) // Think: can we optimize here with binary search?
            { 
                subS = strs[minIndex].substr(0, i+1);
                int count = 0;
                for(int j = 0 ; j < strs.size() ; j++)
                {
                   
                    if(j != minIndex)
                    {
                        if(strs[j].find(subS) == 0) 
                        {
                            count++;
                        }
                    }
                }
                if(count == strs.size()-1)
                {
                    found = true;
                    break;
                }
            }
            return (found ? subS : "");
        }
    };