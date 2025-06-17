class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int stock = INT_MAX;
            int profit = 0;
            for(int i=0;i<prices.size();i++){
                stock = min(prices[i] , stock);
                profit = max(profit,prices[i]-stock);
            }
            return profit;
        }
    };