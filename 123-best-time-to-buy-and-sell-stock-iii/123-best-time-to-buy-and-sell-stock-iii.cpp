class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        
        vector<vector<int>> after(2, vector<int>(3));
        vector<vector<int>> curr(2, vector<int>(3));
        
        for(int i = n-1; i >= 0; i--){
            for(int b = 0; b <= 1; b++){
                for(int c = 1; c <= 2; c++){
                    if(b == 1){
                        curr[b][c] = max(-a[i]+after[0][c],
                                        0+after[1][c]);
                    }else{
                        curr[b][c] = max(a[i]+after[1][c-1],
                                        0+after[0][c]);
                    }
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};