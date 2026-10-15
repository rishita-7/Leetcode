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
    bool res=false;
    void fun(TreeNode* root, int sum, int targetSum){
        if(!root)
            return;
        sum+=root->val;
        if(!root->left && ! root->right && sum==targetSum){
            res=true;
            return;
        }
        fun(root->left,sum,targetSum);
        fun(root->right,sum, targetSum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        fun(root,0,targetSum);
        return res;
    }
};