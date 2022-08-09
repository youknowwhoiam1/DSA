class Solution {
public:
    bool ispalindrome(int i, int j, string &s){
        if(i >= j){return true;}
        if(s[i] != s[j]){return false;}
        return ispalindrome(i+1,j-1,s);
    }
    
    int solve(int i, int n, string &s, vector<int> &dp){
        if(i == n){return 0;}
        if(dp[i] != -1){return dp[i];}
        int minCost = INT_MAX;
        for(int j = i; j < n; j++){
            if(ispalindrome(i,j,s)){
                int cost = 1 + solve(j+1,n,s,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(0,n,s,dp)-1;
    }
};