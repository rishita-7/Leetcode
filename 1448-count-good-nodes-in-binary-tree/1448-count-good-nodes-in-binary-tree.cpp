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
    int postOrder(TreeNode* root,int maxEle){
        if(root==nullptr)
            return 0;
        int left=postOrder(root->left,max(root->val,maxEle));
        int right=postOrder(root->right,max(root->val,maxEle));

        if(root->val >=maxEle)
            return 1+left+right;
        return left+right;
    }
    int goodNodes(TreeNode* root) {
       int count=postOrder(root,INT_MIN);
       return count;
    }
};