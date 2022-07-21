class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> psum(n+1);
        for(int i = 1; i <= n; i++){
            psum[i] = psum[i-1] + nums[i-1];
        }
        vector<int> ssum(n+2);
        for(int i = n; i >= 1; i--){
            ssum[i] = ssum[i+1] + nums[i-1];
        }
        int ans = -1;
        for(int i = 0; i <= n-1; i++){
            if(psum[i] == ssum[i+2]){
                ans = i; break;
            }
        }
        return ans;
    }
};