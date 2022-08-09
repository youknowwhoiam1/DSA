class Solution {
public:
    vector<vector<string>> ans;

    bool ispalindrome(string s, int n) {
        for (int i = 0; i <= n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void solve(string s, int j, int n, vector<string> v) {
        if (j == n) {ans.push_back(v); return;}
        for (int i = 1; i <= n - j; i++) {
            string x = s.substr(j, i);
            if (ispalindrome(x, i)) {
                vector<string> l = v;
                l.push_back(x);
                solve(s, j + i, n, l);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> v;
        solve(s, 0, n, v);
        return ans;
    }
};