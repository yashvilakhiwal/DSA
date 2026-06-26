class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<int> maxi(n);
        maxi[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxi[i] = max(maxi[i + 1], prices[i]);
        }
        for(int i = 0; i < n; i++) {
            int currProfit = maxi[i] - prices[i];
            profit = max(currProfit, profit);
        }
        return profit;
    }
};