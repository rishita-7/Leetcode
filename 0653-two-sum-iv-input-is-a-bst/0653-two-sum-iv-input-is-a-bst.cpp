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
    vector<int> elements;
    void inOrder(TreeNode* root){
        if(!root)
            return;
        inOrder(root->left);
        elements.push_back(root->val);
        inOrder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int left=0,right=elements.size()-1;
        while(left<right){
            if(elements[left]+elements[right] == k)
                return true;
            if(elements[left] + elements[right] > k)
                right--;
            else
                left++;
        }
        return false;
    }
};