//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int N = 1005;

vector<int> par(N);
vector<int> size_of_node(N);

void makeset(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        size_of_node[i] = 1;
    }
}

int get_par(int v) {
	if (v == par[v])
		return v;
	return par[v] = get_par(par[v]);
}

void union_set(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if (a != b) {
        if (size_of_node[a] < size_of_node[b])
            swap(a, b);
        par[b] = a;
        size_of_node[a] += size_of_node[b];
    }
}

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        makeset(V);
    	set<pair<int, pair<int, int>>> v;
    	for (int i = 0; i < V; i++) {
    		for (auto j : adj[i]) {
    			v.insert({j[1], {min(i, j[0]), max(i, j[0])}});
    		}
    	}
    	int sum = 0;
    	for (auto it = v.begin(); it != v.end(); it++) {
    		int x = (*it).second.first;
    		int y = (*it).second.second;
    
    		if (get_par(x) != get_par(y)) {
    			union_set(x, y);
    			sum += (*it).first;
    		}
    	}
    
    	return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends