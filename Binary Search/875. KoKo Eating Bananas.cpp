class Solution {
    // Que:
    // Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
    // Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
    // If the pile has less than k bananas, she eats all of them instead and 
    // will not eat any more bananas during this hour.
    // Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
    // Return the minimum integer k such that she can eat all the bananas within h hours.

    // Example 1:
    // Input: piles = [3,6,7,11], h = 8
    // Output: 4

    // Example 3:
    // Input: piles = [30,11,23,4,20], h = 6
    // Output: 23

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // Corner Case 1:
        if(piles.size() == 1)
            return ceil((long double)piles[0]/h);


        // Intution:
        // First need to understand 
        int maxPile = 0;

        
        for(long i = 0 ; i < piles.size() ; i++)
        {
            maxPile = max(piles[i], maxPile);
        }

        //have to find optimal value of k which may range from 1 to maxPile
        //so that Koko can finish in given hr

        long L = 1;
        long R = maxPile;
        long midK = 0;

        while(L <= R)
        {
            midK = (L+R)/2;
            long long hrtaken = 0; 
            //calculate hrs taken by KoKo to eat all piles
            for(auto &totalBananasInpile : piles)
            {
                hrtaken += ceil((long double)totalBananasInpile/midK);
            }
            if(hrtaken == h)
            {
                break;
            }
            else if(hrtaken > h)
            {
                L = midK+1;
            }
            else
                R = midK-1;
        }
        return midK;

        
    }
};