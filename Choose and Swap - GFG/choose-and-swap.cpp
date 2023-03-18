//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 

class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        ll i, j;
    	ll n = a.length();
    	set<char> s;
    	map<char, ll> m;
    	ll idx = -1;
    	for (i = 0; i < n; i++) {
    		if (m[a[i]] == 0) {
    			s.insert(a[i]);
    			auto it = s.end();
    			it--;
    			if (a[i] != *it) {
    				if (idx != -1) {
        				if (a[i] < a[idx]) {
        					idx = i;
        				}
        			}else{
    				    idx = i;
    				}
    			}
    			m[a[i]]++;
    		}
    	}
    	if (idx == -1) {
    		return a;
    	}
    	char z;
    	for (i = 0; i < idx; i++) {
    		if (a[i] > a[idx]) {
    			z = a[i];
    			break;
    		}
    	}
    	char x = z, y = a[idx];
    	for (i = 0; i < n; i++) {
    		if (a[i] == x) {
    			a[i] = y;
    		} else if (a[i] == y) {
    			a[i] = x;
    		}
    	}
    	return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends