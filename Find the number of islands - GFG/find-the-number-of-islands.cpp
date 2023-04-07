//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    vector<int> dx = { -1, 1, 0, 0, 1, 1, -1, -1};
    vector<int> dy = {0, 0, -1, 1, -1, 1, 1, -1};
    
    void f(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    	vis[i][j] = true;
    	if (grid[i][j] == '1') {
    		for (int k = 0; k < 8; k++) {
    			int x = i + dx[k], y = j + dy[k];
    			if (x >= 0 and x < n and y >= 0 and y < m
    			        and vis[x][y] == false) {
    				f(x, y, n, m, grid, vis);
    			}
    		}
    	}
    }
    
    int numIslands(vector<vector<char>>& grid) {
    	// Code here
    	int n = grid.size();
    	int m = grid[0].size();
    	int cnt = 0;
    	vector<vector<bool>> vis(n, vector<bool>(m, false));
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			if (grid[i][j] == '1' and vis[i][j] == false) {
    				f(i, j, n, m, grid, vis);
    				cnt++;
    			}
    		}
    	}
    	return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends