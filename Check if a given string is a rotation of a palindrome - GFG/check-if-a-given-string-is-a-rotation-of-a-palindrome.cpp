//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:
	
	bool ispalindrome(string s){
	    int n = s.length();
	    for(int i = 0; i < n/2; i++){
	        if(s[i] != s[n-i-1]){
	            return false;
	        }
	    }
	    return true;
	}
	
	int isRotatedPalindrome(string s){
	    // code here
    	        
        if (ispalindrome(s))
            return true;
     
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            string s1 = s.substr(i + 1, n - i - 1);
            string s2 = s.substr(0, i + 1);
     
            if (ispalindrome(s1.append(s2)))
                return true;
        }
        return false;	    
	}
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isRotatedPalindrome(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends