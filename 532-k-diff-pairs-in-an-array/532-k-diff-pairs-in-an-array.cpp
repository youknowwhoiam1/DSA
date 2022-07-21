class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        int n = nums.size();
        set<pair<int,int>> s;
        for(int i = 0; i < n; i++){
            if(m[nums[i]-k]){
                s.insert({nums[i],nums[i]-k});
            }
            if(m[nums[i]+k]){
                s.insert({nums[i]+k,nums[i]});
            }
            m[nums[i]]++;
        }
        int ans = s.size();
        return ans;
    }
};