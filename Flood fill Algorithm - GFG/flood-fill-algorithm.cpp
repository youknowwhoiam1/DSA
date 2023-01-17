//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int v, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans){
        vis[v] = true;
        ans[v] = 1;
        for(auto u:adj[v]){
            if(!vis[u]){
                dfs(u, adj, vis, ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> adj(n*m);
        vector<bool> vis(n*m, false);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j+1 < m and image[i][j] == image[i][j+1]){
                    int x = i*m + j, y = i*m + j+1;
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                }
                if(i+1 < n and image[i][j] == image[i+1][j]){
                    int x = i*m + j, y = (i+1)*m + j;
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                }
            }
        }
        
        vector<int> ans(n*m);
        
        int v = m*sr + sc;
        
        dfs(v, adj, vis, ans);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int index = i*m + j;
                if(ans[index] == 1){
                    image[i][j] = newColor;
                }
            }
        }
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends