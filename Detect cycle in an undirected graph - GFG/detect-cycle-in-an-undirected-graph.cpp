//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        vector<bool> vis1(V, false);
        for(int i = 0; i < V; i++){
            if(vis[i] == false){
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    vis1[v] = true;
                    for(auto u : adj[v]){
                        if(vis[u] and !vis1[u]){
                            return 1;
                        }
                        if(!vis[u]){
                            q.push(u);
                            vis[u] = true;
                        }
                    }
                }
            }
        }
        return 0;
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