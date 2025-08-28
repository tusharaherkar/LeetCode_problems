class Solution {
    public:
    
        string encode(vector<string>& strs) {
    
            // Algo:
            // Decided to encode given input ["neet", "code", "love", "you"]in below format
            // 4,4,4,3#neetcodeloveyou
            // Encode algo: 
            // 1. All string lengths to be attached at the beginning 
            // 2. then append one #
            // 3. then have all the strings appended without whitespace
    
            if(strs.size() == 0)
                return "";
            
            vector <int> strslen;
            
            //Get all the lengths in strslen vetor
            // cout<<"lengths: ";
            for (int i = 0 ; i < strs.size(); i++)
            {
                strslen.push_back(strs[i].length());
                //cout<<" "<<strs[i].length();
            }
            //cout<<endl;
    
            string op; 
            //Append all the stringlengths attached at the beginning separated by ,
            op+=to_string(strslen[0]);
    
            for (int i = 1 ; i < strslen.size(); i++)
            {
                op += "," + to_string(strslen[i]);
    
            }
            //end the string lengths with #
            op += "#";
    
            //append all the strings in raw format without whitespace
            for (int i = 0 ; i < strs.size(); i++)
            {
                op+=strs[i];
            }
    
            //cout<<op<<endl;
            return op;
            
    
        }
    
        vector<string> decode(string s) {
                
            //decode the string with reverse of encoding
            // First get all the string lengths in strlens vector till #
            // then use strlens to form separated Strings 
            vector <string> seperatedStrs;

            //Corner Case 1:
            if(s.length() == 0)
                return seperatedStrs;

            vector <int> strlens;
            int j = 0;
    
            int i = 0;
    
            for (i = 0 ; i < s.length(); i++)
            {
    
                string temp;
                while(s[i] != ',' && s[i] != '#')
                {
                    temp+=s[i];
                    i++;
                }
    
                strlens.push_back(stoi(temp));
    
                if(s[i] == '#')
                    break;
            }
            //inc by one to go to the next part after #
            i++;
            
            for(int strlensIter = 0 ; strlensIter < strlens.size() ; strlensIter++)
            {
               
                //cut the string with the help of strlens
                int len = strlens[strlensIter];
                //cout<<"len: "<<len <<" str: "<< s.substr(i, len)<<endl;
                seperatedStrs.push_back(s.substr(i, len));
                i += len;
            }
        
            return seperatedStrs;
        }
    };
    