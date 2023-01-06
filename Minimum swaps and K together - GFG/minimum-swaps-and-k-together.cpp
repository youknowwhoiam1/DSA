//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int a[], int n, int k) {
        int m = 0;
        for(int i = 0; i < n; i++){
            if(a[i] <= k){m++;}
        }
        int ans = m, len = 0, cur = 0;
        for(int i = 0; i < n; i++){
            if(len < m){
                len++;
                if(a[i] <= k){
                    cur++;
                }
                if (len == m) {
        			ans = min(ans, m - cur);
        		}
            }else{
                if(a[i] <= k){
                    cur++;
                }
                if(a[i-m] <= k){
                    cur--;
                }
                ans = min(ans, m-cur);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends