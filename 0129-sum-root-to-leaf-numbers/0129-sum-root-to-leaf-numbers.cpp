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
    int dfs(TreeNode* node, int curr_val){
        if(node==nullptr){
            return 0;
        }
        curr_val=curr_val*10+node->val;
        if(node->left==nullptr && node->right==nullptr)
            return curr_val;
        return (dfs(node->left,curr_val)+dfs(node->right,curr_val));
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};