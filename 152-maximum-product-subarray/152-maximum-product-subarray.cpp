class Solution {
public:
    int ans = INT_MIN;
    
    void getans(vector<int> v){
        int x = 1, n = v.size();
        int len = n;
        for(int i = 0; i < n; i++){
            x *= v[i];
        }
        if(x<0){
            int p = 1, q = 1, r = 1;
            int l1 = 0, l2 = 0;
            for(int i = 0; i < n; i++){
                p *= v[i]; l1++;
                if(v[i] < 0){
                    break;
                }
            }
            for(int i = n-1; i >= 0; i--){
                q *= v[i]; l2++;
                if(v[i] < 0){
                    break;
                }
            }
            if(p >= q){
                r = p;
                len -= l1;
            }else{
                r = q;
                len -= l2;
            }
            x /= r;
        }
        if(len){
            ans = max(ans,x);
        }
    }
    
    int maxProduct(vector<int>& a) {
        vector<vector<int>> v;
        vector<int> t;
        int n = a.size();
        ans = INT_MIN;
        for(int i = 0; i< n; i++){
            ans = max(ans, a[i]);
        }
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                if(t.size() != 0){
                    v.push_back(t);
                }
                t.clear();
            }else{
                t.push_back(a[i]);
            }
        }
        if(t.size() != 0){
            v.push_back(t);
        }
        int sz = v.size();
        for(int i = 0; i < sz; i++){
            getans(v[i]);
        }
        return ans;
    }
};