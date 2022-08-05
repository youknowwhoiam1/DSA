class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int idx = -1, s = 0;
        for(int i = 0; i < n; i++){
            if(gas[i] >= cost[i]){
                if(s == 0){idx = i;}
                s += gas[i]-cost[i];
            }else{
                s += gas[i]-cost[i];
            }
            if(s < 0){
                s = 0; idx = -1;
            }
        }
        if(idx == -1){return -1;}
        int j = n, ctr = 0;
        while(j--){
            int i = idx%n;
            ctr += gas[i]-cost[i];
            ++idx;
            if(ctr < 0){return -1;}
        }
        return idx%n;
    }
};