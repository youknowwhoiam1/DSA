//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool dfs(int v, vector<int>&vis, vector<int>adj[], vector<int>&vis1, vector<int>&safe){
        vis[v] = 1;
        vis1[v] = 1;
        safe[v] = 0;
        for(auto u : adj[v]){
            if(!vis[u]){
                if(dfs(u, vis, adj, vis1, safe) == true){
                    safe[v] = 0;
                    return true;
                }
            }else if(vis1[u]){
                safe[v] = 0;
                return true;
            }
        }
        safe[v] = 1;
        vis1[v] = 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V), vis1(V), safe(V);
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                dfs(i,vis,adj,vis1,safe);
            }
        }
        for(int i = 0; i < V; i++){
            if(safe[i] == 1){
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends