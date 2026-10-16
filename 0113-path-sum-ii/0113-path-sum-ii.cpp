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
    vector<vector<int>> res;
    void fun(TreeNode* root, int sum, int targetSum , vector<int> & path){
        if(!root)
            return;
        sum+=root->val;
        path.push_back(root->val);
        if(!root->left && ! root->right && sum==targetSum){
            res.push_back(path);
            path.pop_back();
            return;
        }
        fun(root->left,sum,targetSum,path);
        fun(root->right,sum,targetSum,path);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        fun(root,0,targetSum,path);
        return res;
    }
};