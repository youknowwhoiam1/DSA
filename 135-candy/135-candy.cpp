class Solution {
public:
    int candy(vector<int>& a) {
        vector<pair<int,int>> v;
        int n = a.size();
        for(int i = 0; i < n; i++){
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> c(n,1);
        for(int i = 0; i < n; i++){
            int j = v[i].second;
            if(j-1 >= 0 and a[j-1] > a[j] and c[j-1] <= c[j]){
                c[j-1] = c[j]+1;
            }
            if(j+1 < n and a[j+1] > a[j] and c[j+1] <= c[j]){
                c[j+1] = c[j]+1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){ans += c[i];}
        return ans;
    }
};