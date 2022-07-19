class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, curr = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,nums[i]);
        }
        for(int i = 0; i < n; i++){
            curr += nums[i];
            if(curr < 0){curr = 0;}
            else{ans = max(ans,curr);}
        }
        return ans;
    }
};