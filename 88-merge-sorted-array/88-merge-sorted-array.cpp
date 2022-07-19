class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m);
        for(int i = 0; i < m; i++) {
            v[i] = nums1[i];
        }
        int x = 0, y = 0;
        for(int i = 0; i < n+m; i++){
            if(x == m) {
                nums1[i] = nums2[y]; y++;
            }else if(y == n){
                nums1[i] = v[x]; x++;
            }else{
                if(v[x] < nums2[y]){
                    nums1[i] = v[x]; x++;
                }else{
                    nums1[i] = nums2[y]; y++;
                }
            }
        }
    }
};