/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int solve(TreeNode* v){
        if(!v){return 0;}
        int l = max(solve(v->left),0);
        int r = max(solve(v->right),0);
        int temp = max(l+r+v->val, v->val);
        ans = max(ans,temp);
        return v->val+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};