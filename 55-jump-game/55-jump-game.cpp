class Solution {
public:
    bool canJump(vector<int>& a) {
        map<int,int> m;
        int n = a.size();
        for(int i = 0; i < n; i++){
            m[i] = a[i]+i;
        }
        int idx = -1;
        for(int i = n-2; i >= 0; i--){
            if(a[i] == 0){
                if(idx != -1){continue;}
                idx = i;
            }else{
                if(m[i] > idx){
                    idx = -1;
                }    
            }
        }
        if(idx == -1){return true;}
        return false;
    }
};