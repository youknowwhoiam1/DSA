class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size() == 1){return intervals;}
        vector<int> V;
        int n = intervals.size();
        int L,R;
        for(int i = 0; i < n; i++){
            if(i == 0){
                L = intervals[i][0];
                R = intervals[i][1];
            }else{
                if(intervals[i][0] <= R){
                    R = max(R, intervals[i][1]);
                }else{
                    V.push_back(L);
                    V.push_back(R);
                    L = intervals[i][0];
                    R = intervals[i][1];
                }
                if(i == n-1){
                    V.push_back(L);
                    V.push_back(R);
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < V.size(); i+=2){
            vector<int> k;
            k.push_back(V[i]);
            k.push_back(V[i+1]);
            ans.push_back(k);
        }
        return ans;
    }
};