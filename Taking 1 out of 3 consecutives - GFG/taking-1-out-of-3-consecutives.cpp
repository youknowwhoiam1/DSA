//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int minSum(int a[], int n)
    {
        if(n<3){return 0;}
        // Write your code here
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(i < 3){
                dp[i] = a[i];
            }else{
                dp[i] = a[i] + min({dp[i-1], dp[i-2], dp[i-3]});
            }
        }   
        // for(int i = 0; i < n; ++i){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return min({dp[n-1], dp[n-2], dp[n-3]});
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
		cin>>n;
		int a[n+5];
    	for(int i=0;i<n;i++)
    		cin>>a[i];
    	Solution ob;
    	cout<<ob.minSum(a, n)<<endl;
    	
	}
	return 0;
}
// } Driver Code Ends