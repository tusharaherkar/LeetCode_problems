class Solution {
    public:
        vector<int>  topKFrequentusingBucketSort(vector<int>& nums, int k){
            unordered_map <int, int> freq;

            for(auto &it: nums)
            {
                freq[it]++;
            }

            vector < vector <int> > BucketCount(nums.size()+1); // It is initialized to nums.size()+1 
                                                                // because if only one element is repeated for in whole nums
            
            // check value of freq which is freq of elements 
            // and bucket the to the appropriate bucket of freq as incdex in BucketCount
            for(auto it : freq)
            {
                BucketCount[it.second].push_back(it.first);
            }
            
            
            vector <int> Soln;
            int count = 0;
            //Traverse BucketCount in reverse direction and push_back top K freq
            for(auto it = BucketCount.rbegin() ; it != BucketCount.rend() ; it++)
            {
                if(count < k)
                {
                    for(auto &itt : *it)
                    {
                        Soln.push_back(itt);
                    }
                    count += it->size();
                }
                else
                    return Soln;
            }

                                                        
            return Soln;

        }
        vector<int> topKFrequent(vector<int>& nums, int k) {
            
            // Algo 1:
            // 1. unordered_map <int, int> is getting used for storing the unique element as key
            //    and its freq as value
            // 2. map <int, vector<int>> KfreqElements is used when the value in first map will be key in second map
            // 3. This is done because there can be two or any no. of unique elements in given input array having same freq so 
            //   i.e. values of first map named freq can have multiple values which are exactly same
            // 4. Now if the value is same then push_back into the vector corresponding to the key of KfreqElements;
            // 5. Return top K from bottom of kfreqElements as it is map so It will be always in sorted order

            // Time Complexity Analysis:
            // 1. Need to traverse entire array atleast once to store freq here O(N)
            // 2. KfreqElements map stores key and value in sorted order here O(NlogN)

            // Space Complexity Analysis
            // 1. Extra space of map named freq and KfreqElements would occupy O(2N)
            // Which would round upto O(N)


            //Algo 2 (Bucket Sort):
            // 1. declare unordered_map <int, int> should store the element and its freq
            // 2. declare vector< vector<int>> to store the freq as indexing inside vector and elements as vector of int which belongs to that freq.
            // 3. vector< vector<int>> traverse the array and get top k elements
            
            return topKFrequentusingBucketSort(nums, k);


            //soln is used to store the Soln
            vector <int> Soln;
            
            // This is to store the frequencies of each unique elements from nums
            unordered_map <int, int> freq;
            
            // This is to store values of first freq map as keys and keys as vector of int as values in KfreqElements
            map <int, vector<int>> KfreqElements;
    
            // Calculate the freq and store it in freq
            for(auto &it: nums)
            {
                freq[it]++;
            }
            
            //get the values of freq and store them as keys for KfreqElements
            // and push_back key of freq as  value vector for KfreqElements
            for(auto &it : freq)
            {
                int key = it.second;
                
                KfreqElements[key].push_back(it.first);
                //cout<<"ele: "<<it.first <<" freq: " <<it.second<<endl;
            }
            
            //Initialize count as 0
            int count = 0;

            //traverse KfreqElements from end and push k amount of elements in Soln
            //Once done return Soln;
            for(auto it = KfreqElements.rbegin(); it != KfreqElements.rend() ; it++)
            {
                
                if(count < k)
                {
                    for(auto &itt : it->second)
                    {
                        Soln.push_back(itt);
                    }
                    
                    
                    count+= it->second.size();
                }
                else
                    return Soln;
            }
            
           return Soln;
            
        }
    };