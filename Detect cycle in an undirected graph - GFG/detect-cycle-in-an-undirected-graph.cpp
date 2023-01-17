//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    int ans = 0;
    
    void dfs(int v, vector<int> *adj, vector<bool> &vis){
        vis[v] = true;
        int cnt = 0;
        for(auto u : adj[v]){
            if(vis[u]){cnt++;}
            else{
                dfs(u, adj, vis);
            }
        }
        if(cnt>1){ans=1;}
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++){
            if(vis[i] == false){
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends