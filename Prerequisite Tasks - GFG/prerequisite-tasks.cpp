//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    for(int i = 0; i < prerequisites.size(); i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<int> deg(N);
	    for(int i = 0; i < N; i++){
	        for(auto j : adj[i]){
	            deg[j]++;
	        }
	    }    
	    vector<int> ideal;
	    for(int i = 0; i < N; i++){
	        ideal.push_back(i);
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
	        for(auto u : adj[v]){
	            deg[u]--;
	            if(deg[u] == 0){
	                q.push(u);
	            }
	        }
	    }
	    sort(topsort.begin(), topsort.end());
	    if(topsort == ideal){
	        return true;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends