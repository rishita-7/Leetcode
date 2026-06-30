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
    pair<int,int> postOrder(TreeNode* root){
        if(root==nullptr)
            return {0,0};
        auto[left_include,left_exclude]=postOrder(root->left);
        auto[right_include,right_exclude]=postOrder(root->right);
        int include=root->val + left_exclude + right_exclude;
        int exclude=max(left_include,left_exclude) + max(right_include,right_exclude);
        return {include,exclude};
    }
    int rob(TreeNode* root) {
        auto[i,e]=postOrder(root);
        return max(i,e);
    }
};