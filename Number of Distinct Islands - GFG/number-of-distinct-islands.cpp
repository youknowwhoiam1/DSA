//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
  
    void f(int rel_i, int rel_j, int i, int j, int n, int m, vector<vector<int>>& g, vector<vector<bool>>& vis, vector<pair<int,int>> &points){
        points.push_back({rel_i, rel_j});
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int x = i+dx[k], y = j+dy[k];
            int rel_x = rel_i+dx[k], rel_y = rel_j+dy[k];
            if(x >= 0 and x < n and y >= 0 and  y < m and vis[x][y] == 0 and g[x][y] == 1){
                f(rel_x, rel_y, x, y, n, m, g, vis, points);
            }
        }
    }
  
  public:
    int countDistinctIslands(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        map<vector<pair<int,int>>,int> k;
        vector<vector<bool>> vis(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 and g[i][j] == 1){
                    vector<pair<int,int>> points;
                    f(0,0,i,j,n,m,g,vis,points);
                    sort(points.begin(), points.end());
                    k[points]++;
                }
            }
        }
        return k.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends