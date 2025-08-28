class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //Algo/ Intution 
        // 1. Declare  a set of int 
        // 2. Traverse the input array nums
        // 3. while traversing, check the current element is present in a set 
        // 4. if yes return true i.e. having duplicate otherwise insert that element into the set
        
        
        //Define the set for inserting values in it
        set <int> Set;

        //Traverse input array
        for(auto &it : nums)
        {
            //cout << " " << it <<endl;
            //Check if it is already available in set
            if(Set.count(it)) 
                return true;// return expected bool-true if duplicate value came while traversing over input array

            Set.insert(it); 
        }

        return false;
        
    }
};