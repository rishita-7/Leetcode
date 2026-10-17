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
    TreeNode* prev=nullptr;
    bool ans=true;
    void inOrder(TreeNode* root){
        if(!root)
            return;
        inOrder(root->left);
        if(prev==nullptr)
            prev=root;
        else{
            if(root->val <= prev->val){
                ans=false;
                return;
            }
            prev=root;
        }
        inOrder(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};