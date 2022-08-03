class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        char dir = 'r';
        vector<int> ans;
        int i = 0, j = 0;
        ans.push_back(matrix[i][j]);
        vis[i][j] = 1;
        while (1) {
            int ok = 1;
            if (i + 1 < n and vis[i + 1][j] == 0) {ok = 0;}
            if (j + 1 < m and vis[i][j + 1] == 0) {ok = 0;}
            if (j - 1 >= 0 and vis[i][j - 1] == 0) {ok = 0;}
            if (i - 1 >= 0 and vis[i - 1][j] == 0) {ok = 0;}
            if (ok == 1) {break;}
            if (dir == 'r') {
                if (j + 1 < m and vis[i][j + 1] == 0) {
                    ans.push_back(matrix[i][j + 1]);
                    vis[i][j + 1] = 1;
                    j++;
                } else {
                    dir = 'd';
                }
            } else if (dir == 'd') {
                if (i + 1 < n and vis[i + 1][j] == 0) {
                    ans.push_back(matrix[i + 1][j]);
                    vis[i + 1][j] = 1;
                    i++;
                } else {
                    dir = 'l';
                }
            } else if (dir == 'l') {
                if (j - 1 >= 0 and vis[i][j - 1] == 0) {
                    ans.push_back(matrix[i][j - 1]);
                    vis[i][j - 1] = 1;
                    j--;
                } else {
                    dir = 'u';
                }
            } else if (dir == 'u') {
                if (i - 1 >= 0 and vis[i - 1][j] == 0) {
                    ans.push_back(matrix[i - 1][j]);
                    vis[i - 1][j] = 1;
                    i--;
                } else {
                    dir = 'r';
                }
            }
        }
        return ans;
    }
};