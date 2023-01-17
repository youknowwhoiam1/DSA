//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& g) {
        // Code here
        int n = g.size(), m = g[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] == 1){
                        cnt++;
                    }
                }
        }
        if(cnt == 0){return 0;}
        int prev = 0, cur = 0, ans = 0;
        vector<pair<int,int>> v;
        while(1){
            for(int i = 0; i < v.size(); i++){
                g[v[i].first][v[i].second] = 2;
            }
            v.clear();
            ans++;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] == 1){
                        int ok = 0;
                        if(i-1>=0 and g[i-1][j] == 2){ok=1;}
                        if(j-1>=0 and g[i][j-1] == 2){ok=1;}
                        if(i+1<n and g[i+1][j] == 2){ok=1;}
                        if(j+1<m and g[i][j+1] == 2){ok=1;}
                        if(ok){v.push_back({i,j}); cur++;}
                    }
                }
            }
            if(cur == cnt){break;}
            if(cur == prev){return -1;}
            prev = cur;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends