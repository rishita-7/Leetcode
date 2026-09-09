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
    void inorder(TreeNode* root, vector<int>&arr){
        if(!root)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>l1,l2;
        inorder(root1,l1);
        inorder(root2,l2);
        int i=0,j=0;
        vector<int>res;
        while(i<l1.size() && j<l2.size()){
            if(l1[i]<=l2[j]){
                res.push_back(l1[i]);
                i++;
            }
            else{
                res.push_back(l2[j]);
                j++;
            }
        }
        while(i<l1.size()){
            res.push_back(l1[i]);
            i++;
        }
        while(j<l2.size()){
            res.push_back(l2[j]);
            j++;
        }
        return res;
    }
};