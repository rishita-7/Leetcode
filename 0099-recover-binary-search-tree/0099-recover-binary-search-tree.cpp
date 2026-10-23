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
    TreeNode* prev= nullptr;
    TreeNode* first=nullptr;
    TreeNode* second= nullptr;
    void inOrder(TreeNode* root){
        if(!root)
            return;
        inOrder(root->left);
        if (prev!=nullptr && prev->val > root->val){
            if(first==nullptr){
                first=prev;
                second=root;
            }
            else{
                second=root;
            }
        }
        prev=root;
        inOrder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        if(first!=nullptr && second!=nullptr)
            swap(first->val, second->val);
        return;
    }
};