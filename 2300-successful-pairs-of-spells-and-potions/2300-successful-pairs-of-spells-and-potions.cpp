class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({spells[i], i});
        }
        sort(v.begin(), v.end());
        int cur = 0, j = 0;
        vector<int> ans(n);
        for (int i = m - 1; i >= 0; i--) {
            long long x = (long long)v[j].first * (long long)potions[i];
            if (x >= success) {
                cur++;
            } else {
                ans[v[j].second] = cur;
                j++;
                cur = 0;
                ++i;
            }
            if (j == n) {break;}
        }
        if (cur != 0) {
            ans[v[j].second] = cur;
        }
        j = 1;
        while (j != n) {
            ans[v[j].second] += ans[v[j - 1].second];
            j++;
        }
        return ans;
    }
};