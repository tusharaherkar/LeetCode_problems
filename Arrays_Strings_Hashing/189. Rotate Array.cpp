class Solution {
    public:
        void rotateOptimized(vector<int>& nums, int k) {
            // Algo 3 is most optimized
    
            // 1. First reverse all the elements of given input
            // 2. then reverse last nums.size()-k elements
            // 3. then reverse first k elements 
            // The final array will be the output array
    
            k = k % nums.size();
    
            reverse(nums.begin(), nums.end());
            reverse(nums.end()-(nums.size()-k), nums.end());
            reverse(nums.begin(), nums.begin()+k);
    
        }
        void rotate(vector<int>& nums, int k) {
            // Algo 3:
            return rotateOptimized(nums, k);
    
            // Algo 1:
            // if K > nums.size() we need to make it withing nums,size()
            // So K = K % nums.size()
            // if K != 0 then only do
            // first get the last K elements of nums at the beginning of temp
            // append all elements from begining to end - K into temp
            // Now copy the vector temp to nums to have it in place
    
            int n = nums.size();
            k = k % n;
            if (k != 0) {
                vector<int> temp(nums.end() - k, nums.end());
                temp.insert(temp.end(), nums.begin(), nums.end() - k);
                copy(temp.begin(), temp.end(), nums.begin());
            }        
            return;
    
            // Algo 2:
            // this is similar algo as Algo 1
            // But it will avoid using extra temp vector which is used in Algo 1
    
            int count = nums.size();
    
            count = k % count;
    
            if(count == 0)
                return;
    
    
            while(count--)
            {
                int popped = nums.back();
                //nums.pop_back();
                nums.erase(nums.end()-1);
                nums.insert(nums.begin(), popped);
                //nums.push_front(popped);
            }
            
        }
    };