//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void f(int i, int j, vector<vector<int>> &a, int n, int m, vector<vector<int>> &ctr) {
        int dx[] = { -1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
    
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if ((x >= 0 and x < n) and (y >= 0 and y < m)) {
                if (a[x][y] == 1 and ctr[x][y] == 0) {
                    ctr[x][y] = 1;
                    f(x, y, a, n, m, ctr);
                }
            }
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<int>> ctr(n, vector<int>(m, 0));
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 or j == 0 or i == n - 1 or j == m - 1) and
                        a[i][j] == 1 and ctr[i][j] == 0) {
                    ctr[i][j] = 1;
                    f(i, j, a, n, m, ctr);
                }
            }
        }
    
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 and ctr[i][j] == 0) {
                    ans++;
                }
            }
        }
    
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends