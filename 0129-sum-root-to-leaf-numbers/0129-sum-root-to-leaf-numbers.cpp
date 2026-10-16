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
    int total=0;
    void fun(TreeNode* root, int curr){
        if(!root)
            return;
        curr=curr*10+root->val;
        if(!root->left && !root->right){
            total+=curr;
            return;
        }
        fun(root->left,curr);
        fun(root->right,curr);
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(! root)
            return 0;
        fun(root,0);
        return total;
    }
};