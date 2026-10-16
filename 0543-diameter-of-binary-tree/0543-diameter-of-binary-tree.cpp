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
    int diameter=0;
    int max_path(TreeNode* node){
        if(!node)
            return 0;
        int left_max=max_path(node->left);
        int right_max=max_path(node->right);
        diameter=max(diameter,left_max+right_max);
        return (1+ max(left_max,right_max));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        max_path(root);
        return diameter;
    }
};