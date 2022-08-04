class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int trgt = -a[i];
            int start = i + 1;
            int end = n - 1;
            while (start < end) {
                if (a[start] + a[end] > trgt) {
                    end--;
                }
                else if (a[start] + a[end] < trgt) {
                    start++;
                }
                else {
                    vector<int> triplet = {a[start], a[end], a[i]};
                    ans.push_back(triplet);
                    while (start < end and a[start] == triplet[0]) {
                        start++;
                    }
                    while (start < end and a[end] == triplet[1]) {
                        end--;
                    }
                }
            }
            while (i + 1 < n and a[i] == a[i + 1]) {
                i++;
            }
        }
        return ans;
    }
};