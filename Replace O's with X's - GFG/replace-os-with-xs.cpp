//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void f(int i, int j, vector<vector<char>> &a, int n, int m, vector<vector<int>> &ctr) {
        int dx[] = { -1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
    
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if ((x >= 0 and x < n) and (y >= 0 and y < m)) {
                if (a[x][y] == 'O' and ctr[x][y] == 0) {
                    ctr[x][y] = 1;
                    f(x, y, a, n, m, ctr);
                }
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> a)
    {
        vector<vector<int>> ctr(n, vector<int>(m, 0));
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 or j == 0 or i == n - 1 or j == m - 1) and
                        a[i][j] == 'O' and ctr[i][j] == 0) {
                    ctr[i][j] = 1;
                    f(i, j, a, n, m, ctr);
                }
            }
        }
    
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'X') {ans[i][j] = 'X';}
                else {
                    if (ctr[i][j] == 0) {
                        ans[i][j] = 'X';
                    } else {
                        ans[i][j] = 'O';
                    }
                }
            }
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends