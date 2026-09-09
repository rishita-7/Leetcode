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
void inorder(TreeNode* root,vector<int>&arr){
    if(!root)
        return;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}
    vector<int> findMode(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int max_freq=0;
        unordered_map<int,int> freq;
        for(int n:arr){
            freq[n]++;
            max_freq=max(max_freq,freq[n]);
        }
        vector<int>res;
        for(auto n:freq){
            if(n.second==max_freq)
                res.push_back(n.first);
        }
        return res;
    }
};