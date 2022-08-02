class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = n/2;
        map<int,int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        int ans;
        for(int i = 0; i < n; i++){
            if(m[nums[i]] > cnt){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};