class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int b = INT_MAX;
        for(int i = 0; i < n; i++){
            if(a[i] <= b){
                b = a[i];
            }else{
                ans += a[i]-b;
                b = a[i];
            }
        }
        return ans;
    }
};