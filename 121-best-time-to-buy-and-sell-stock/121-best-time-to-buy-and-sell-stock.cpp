class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = INT_MIN;
        int ans = 0;
        for(int i = prices.size()-1; i >= 0; i--){
            mx = max(mx,prices[i]);
            ans = max(ans, mx-prices[i]);
        }
        return ans;
    }
};