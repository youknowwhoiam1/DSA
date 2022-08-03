class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        map<int,int> l;
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            if(l[nums[i]] == 0){
                v.push_back({-m[nums[i]],nums[i]});
            }
            l[nums[i]]++;
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};