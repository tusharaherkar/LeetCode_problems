class Solution {
    public:
        int BestBuySellSlidingWindow(vector<int>& prices) 
        {
            // Algo:
            // 1. Initialize minBuy to the first day
            // 2. Anyway first day buy and sell will give 0 profit
            // 3. So traverse day will start from day 2
            // 4. Calculate the profit for a day
            // 5. If the we encounter a day where minBuy is less than our tracking minBuy 
            //    then update minBuy with todays price
            // 6. Likewise track maxProfit and return the value

            // Time Complexity Analysis:
            // We have to visit the day atleast once here O(N) - where N is number of days

            // Space Complexity Analysis
            // No extra space required
            // O(1) = constant space

            int minBuy = prices[0];
            int maxProfit = 0;
           
            for(auto &sell : prices)
            {
                maxProfit = max(maxProfit, sell-minBuy);
                minBuy = min(minBuy, sell);
    
            }
            return maxProfit;
    
        }
        int maxProfit(vector<int>& prices) {
    
            return BestBuySellSlidingWindow(prices);
            
            //Algo
            //1. build minprefix 
            //2. build maxSuffix
            //profit will be max of the diff
    
            //1. build minprefixarray
            vector <int> minprefix (prices.size(), 0);
            int minBuy, maxSell;
    
            minBuy = prices[0];
            
            for(int i = 0 ; i < prices.size() ; i++)
            {
                minBuy = min(minBuy, prices[i]);
                minprefix[i] = minBuy;
            }
            //build maxSuffix
            vector <int> maxSuffix (prices.size(), 0);
            maxSell = prices[prices.size()-1];
    
            for(int i = prices.size()-1 ; i >=0 ; i--)
            {
                maxSell = max(maxSell,prices[i]);
                maxSuffix[i] = maxSell;
            }
            //calculate the profit on each day
            maxSell = 0;
            for(int i = 0 ; i < prices.size() ; i++)
            {
                maxSell = max(maxSell,(maxSuffix[i] - minprefix[i]));
            }
            return maxSell;
    
        }
    };