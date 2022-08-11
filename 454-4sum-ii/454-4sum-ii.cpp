class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int,int> m;
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                m[a[i]+b[j]]++;
            }
        }
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < d.size(); j++){
                ans += m[-(c[i]+d[j])];
            }
        }
        return ans;
    }
};