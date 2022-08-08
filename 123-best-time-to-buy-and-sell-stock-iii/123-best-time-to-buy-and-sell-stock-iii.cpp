class Solution {
public:
    int f(vector<int>& a, int i, int t, int n, vector<vector<int>>&dp){
        if(i == n or t == 4){return 0;}
        if(dp[i][t] != -1){return dp[i][t];}
        if(t % 2 == 0){
            return dp[i][t] = max(-a[i]+f(a,i+1,t+1,n,dp),
                                 f(a,i+1,t,n,dp));
        }else{
            return dp[i][t] = max(a[i] + f(a,i+1,t+1,n,dp),
                          f(a,i+1,t,n,dp));
        }
    }
    
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return f(a, 0, 0, n, dp);
    }
};