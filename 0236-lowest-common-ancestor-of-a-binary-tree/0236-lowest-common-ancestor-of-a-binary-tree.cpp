/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans=nullptr;
    int no_descendents(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root)
            return 0;
        int left=no_descendents(root->left,p,q);
        int right=no_descendents(root->right,p,q);
        int self;
        if(root==p || root==q)
            self= left+right+1;
        else
            self=left+right;
        if(self==2 and ans==nullptr)
            ans=root;
        return self;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        no_descendents(root,p,q);
        return ans;
    }
};