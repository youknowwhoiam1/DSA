class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({difficulty[i], -profit[i]});
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int ans = 0;
        int j = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (worker[j] >= v[i].first) {
                cur = max(cur, -v[i].second);
            } else {
                ans += cur;
                j++; --i;
            }
            if (j == m) {break;}
        }
        while (j != m) {
            ans += cur; j++;
        }
        return ans;
    }
};