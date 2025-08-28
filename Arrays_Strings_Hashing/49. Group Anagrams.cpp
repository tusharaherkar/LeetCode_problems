class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
            //Algo/ Intution
            // 1. Declare the unordered_map of <string, vector<string>> where key: sorted string & value: vector<string> which corresponds to sorted key
            // 2. Traverse each string in vector of given strings
            //    Sort each string find that key in map if the key is present 
            //    append/push_back that string into the corresponding key which is sorted string itself
            // 3. if not found add that sorted string as new key and normal string as value in the map
            // 4. traverse map and store values of the map inside vector<vector<string>> amd return it.

            // Time Complexity Analysis:
            // Traverse each string would take O(N) where N is the given number of strings and M is the avg length of each string
            // Sorting each string would take O(M * logM) where M is the avg length of each string
            // so overall for traversing  N strings and sorting would take O(N * MlogM) where N is the given number of strings and M is the avg length of each string

            // Space Complexity Analysis
            // We are storing the each string in map which would take O(N) where N is the given number of strings 

            //Declare the unordered_map of <string, vector<string>> where key: sorted string & value: vector<string> which corresponds to sorted key
            unordered_map<string, vector<string>> mp;
            
            //Traverse each string in vector of given strings
            //    Sort each string find that key in map if the key is present 
            //    append/push_back that string into the corresponding key which is sorted string itself

            for(auto x: strs){
                string word = x;
                sort(word.begin(), word.end());
                mp[word].push_back(x);
            }
            
            // Traverse map and store values of the map inside vector<vector<string>> amd return it.
            vector<vector<string>> ans;
            for(auto x: mp){
                ans.push_back(x.second);
            }
            return ans;
        
        }
    };