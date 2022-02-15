class Solution {
public:

    string longestPalindrome(string s) {
        
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        int maxLen = 1, start = 0;

        for (int i = 0; i < n; i++) {
            if (i + 1 < n and s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                maxLen = 2;
            }
        }

        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }

        string ans = s.substr(start, maxLen);
        return ans;
        
    }
};