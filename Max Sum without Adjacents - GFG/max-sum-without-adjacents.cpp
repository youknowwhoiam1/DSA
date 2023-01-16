//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *a, int n) {
	    // code here
	    int ans = 0, i;
	    vector<int> dp(n);
	    for(i = 0; i < n; i++){
	        if(i == 0){dp[i] = a[i];}
	        else if(i == 1){dp[i] = max(a[i], a[i-1]);}
	        else{
	            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
	        }
	        ans = max(ans, dp[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends