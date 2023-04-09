//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> ideal;
        for(int i = 0; i < V;i++){
            ideal.push_back(i);
        }
        vector<int> deg(V);
	    for(int i = 0; i < V; i++){
	        for(auto j:adj[i]){
	            deg[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(deg[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto u:adj[v]){
                deg[u]--;
                if(deg[u] == 0){
                    q.push(u);
                }
            }
	    }
	    sort(ans.begin(), ans.end());
	   // for(int i = 0; i < ans.size(); i++){cout<<ans[i]<<" ";}cout<<endl;
	    if(ans == ideal){return false;}
	    return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends