#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
// find_by_order, order_of_key

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ordered_set<pair<int,int>> s;
        for (int i = n - 1; i >= 0; i--) {
            s.insert({nums[i],i});
            ans[i] = s.order_of_key({nums[i],i});
        }
        return ans;
    }
};