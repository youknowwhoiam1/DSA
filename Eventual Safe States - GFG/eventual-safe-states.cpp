//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int N, vector<int> adj[]) {
        // code here
        vector<vector<int>> new_adj(N);
        for(int i = 0; i < N; i++){
            for(auto j : adj[i]){
                new_adj[j].push_back(i);
            }
        }
        vector<int> deg(N);
	    for(int i = 0; i < N; i++){
	        for(auto j : new_adj[i]){
	            deg[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i < N; i++){
	        if(deg[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topsort;
	    while(!q.empty()){
	        int v = q.front();
	        q.pop();
	        topsort.push_back(v);
            for(auto u : new_adj[v]){
                deg[u]--;
                if(deg[u] == 0){
                    q.push(u);
                }
            }
	    }
	    sort(topsort.begin(), topsort.end());
	    return topsort;
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