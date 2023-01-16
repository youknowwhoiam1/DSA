//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:

    void dfs(int v, vector<vector<int>> &edge, vector<bool> &vis){
        vis[v] = true;
        for(auto u : edge[v]){
            if(!vis[u]){
                dfs(u, edge, vis);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = adj.size();
        
        vector<vector<int>> edge(n+5);
        vector<bool> vis(n+5, false);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and adj[i][j] == 1){
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                dfs(i, edge, vis);
                ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends