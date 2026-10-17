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
    vector<int>vals;
    void inOrder(TreeNode* node){
        if(!node)
            return;
        inOrder(node->left);
        vals.push_back(node->val);
        inOrder(node->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i=1;i<vals.size();i++){
            if(vals[i]<=vals[i-1])
                return false;
        }
        return true;
    }
};