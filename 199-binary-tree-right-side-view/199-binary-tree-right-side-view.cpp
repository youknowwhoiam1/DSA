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
    vector<int> ans;
    vector<pair<pair<int,int>,int>> Nodes;
    void dfs(TreeNode* v, int l, int s){
        Nodes.push_back({{l,-s},v->val});
        if(v->left != nullptr){
            dfs(v->left, l+1, 2*s);
        }
        if(v->right != nullptr){
            dfs(v->right, l+1, 2*s+1);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){return ans;}
        dfs(root, 1, 1);
        sort(Nodes.begin(), Nodes.end());
        int n = Nodes.size();
        map<int,int> level;
        for(int i = 0 ; i < n; i++){
            if(level[Nodes[i].first.first] == 0){
                ans.push_back(Nodes[i].second);
            }
            level[Nodes[i].first.first]++;
            // cout << Nodes[i].second << " " << Nodes[i].first.first << " " << -Nodes[i].first.second << endl;
        }
        return ans;
    }
};