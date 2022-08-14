class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        int n = p.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({p[i][1],p[i][0]});
        }
        sort(v.begin(),v.end());
        int ans = 0, cur = INT_MIN;
        for(int i = 0; i < n; i++){
            if(cur < v[i].second){
                cur = v[i].first;
                ans++;
            }
        }
        return ans;
    }
};