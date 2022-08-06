class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(a[j] > a[i]){
                    dp[j] = max(dp[j], dp[i]+1);
                    ans = max(ans, dp[j]);
                }
            }
        }
        return ans;
    }
};