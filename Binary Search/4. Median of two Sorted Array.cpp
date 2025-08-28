class Solution {
    // Que: 
    // Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

    // The overall run time complexity should be O(log (m+n)).

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        

        int Len1 = nums1.size();
        int Len2 = nums2.size();

        //Corner Case 1:
        if(Len1 == 0 && Len2 == 0)
            return 0;

        
        // Corner Case 2.a:
        // If all the elements in nums1 are greater than nums2
        // We have to choose partition from nums2 and dont touch nums1 

        //Corner Case 2.b: if Len1 == 0
        if(Len1 == 0 || nums1[0] > nums2[Len2-1])
        {
            //if nums2 has odd number of elements
            if(Len2 % 2)
                return nums2[Len2/2];
            //if nums2 has even number of elements
            else
                return ((double)(nums2[Len2/2] + nums2[Len2/2+1])/2);
        }

        
        // Corner Case 3.a:
        // If all the elements in nums2 are greater than nums1
        // We have to choose partition from nums1 and dont touch nums2 

        // Corner Case 3.b: if Len2 == 0
        if(Len2 == 0 || nums2[0] > nums1[Len1-1])
        {
            //if nums1 has odd number of elements
            if(Len1 % 2)
                return nums1[Len1/2];
            //if nums1 has even number of elements
            else
                return ((double)(nums1[Len1/2] + nums2[Len1/2+1])/2);
        }


        // We have to find the optimal partition with the help of Binary Search
        // For applying Binary search and finding the partition start with min length array

        // So declare two new arrays
        vector <int> &A = nums1;
        vector <int> &B = nums1;

        //Lets assume A will be always of min length
        if(A.size() > B.size())
        {
            swap(A, B);
        }

        int TotalLen = A.size() + B.size();

        int L = 0 ;
        int R = A.size();        

        if(Len1 <= Len2)
        {
            //Apply Binary Search and find right partition
            
            int L = 0, R = Len1-1;
            
            int mid = (L+R)/2;
            
            // partition 1 => nums1  0 - Len1-1
            // partition 2 => nums2  0 to 
            
            int partition2End = (TotalLen - (mid + 1) - 1);

            

            // Check if partition has done correctly or not
            if(nums1[mid] <= nums2[partition2End+1] && nums2[partition2End] <= nums1[mid+1])
            {
                // then partition is correct 
                // Now based on even and odd elements find the partition
                // If the TotalLen is odd
                if(TotalLen%2)
                {
                    return min(nums1[mid+1], nums2[partition2End+1]);
                }
                // if the TotalLen is even
                // then 
                else
                {
                    //then avg of rightmost element of left partition and leftmost element of right partition
                    double result = ((double) (max(nums1[mid], nums2[partition2End]) + min(nums1[mid+1], nums2[partition2End+1]))/2);
                    return result;

                }
            }
            //Again try to find the mid 
            else  if(nums1[mid] <= nums2[partition2End+1])
            {

            }


        }
        else
        {
            
        }


    }
};