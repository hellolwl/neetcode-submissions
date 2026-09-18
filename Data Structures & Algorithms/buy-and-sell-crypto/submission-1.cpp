class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int max_profit = 0;

        for (int r = 0; r < static_cast<int>(prices.size()); r++) {
            if (prices[r] < prices[l]) {
                l = r;
            } else {
                max_profit = max(max_profit, prices[r] - prices[l]);
            }
        }
        
        return max_profit;
    }
};
