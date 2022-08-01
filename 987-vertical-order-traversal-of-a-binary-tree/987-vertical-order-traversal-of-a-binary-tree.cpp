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
    vector<vector<int>> ans;    
    vector<pair<pair<int,int>,int>> Nodes;
    void dfs(TreeNode* v, int r, int c){
        if(v == nullptr){return;}
        Nodes.push_back({{c,r},v->val});
        dfs(v->left, r+1, c-1);
        dfs(v->right, r+1, c+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr){return ans;}
        dfs(root, 0, 0);
        sort(Nodes.begin(), Nodes.end());
        int n = Nodes.size();
        // for(int i = 0; i < n; i++){
        //     cout << Nodes[i].second << " "
        //         << Nodes[i].first.first << " "
        //         << Nodes[i].second << endl;
        // }
        vector<int> t;
        int j = 0;
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            if(mp[Nodes[i].first.first] == 0){
                if(t.size()){
                    ans.push_back(t);
                    t.clear();
                }
                t.push_back(Nodes[i].second);
            }else{
                t.push_back(Nodes[i].second);
            }
            mp[Nodes[i].first.first]++;
        }
        if(t.size()){
            ans.push_back(t);
        }
        return ans;
    }
};