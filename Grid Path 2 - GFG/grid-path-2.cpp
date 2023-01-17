//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& g) {
        // Code here
        int mod = 1e9+7;
        if(g[0][0] == 1 or g[n-1][m-1] == 1){return 0;}
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 0){
                    dp[i][j] += ((i-1>=0 and g[i-1][j] == 0) ? dp[i-1][j] : 0) +
                                ((j-1>=0 and g[i][j-1] == 0) ? dp[i][j-1] : 0);
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends