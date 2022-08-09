class Solution {
public:
    int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp, int n, int m){
        if(i == 0 and j == 0){
            return a[i][j];
        }
        if(dp[i][j] != -1){return dp[i][j];}
        int mincost = INT_MAX;
        if(j-1>=0){
            int cost = a[i][j] + f(i,j-1,a,dp,n,m);
            mincost = min(mincost, cost);
        }
        if(i-1>=0){
            int cost = a[i][j] + f(i-1,j,a,dp,n,m);
            mincost = min(mincost, cost);
        }
        return dp[i][j] = mincost;
    }
    
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,a,dp,n,m);
    }
};