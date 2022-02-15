class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        vector<int> v(128, -1);
        int ans = 0, start = 0;
        map<char,int> m;
        for(int i = 0; i < n; i++){
            if(m[s[i]-0]==0){m[s[i]]=1;v[s[i]-0]=i;}
            else{
                ans = max(ans,i-start);
                cout << i-start << " ";
                start = max(start,v[s[i]-0]+1);
                v[s[i]-0]=i;
                // cout<< i << " " << start << endl;
            }
        }
        ans = max(ans, n-start);
        return ans;
    }
};