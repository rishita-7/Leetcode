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
    int max_sum=INT_MIN;
    vector<int> helper(TreeNode* node){
        if(!node){
            return {1,INT_MAX,INT_MIN,0};
        }
        auto l=helper(node->left);
        int l_bst=l[0];
        int l_min=l[1];
        int l_max=l[2];
        int l_sum=l[3];

        auto r=helper(node->right);
        int r_bst=r[0];
        int r_min=r[1];
        int r_max=r[2];
        int r_sum=r[3];

        if(l_bst && r_bst && l_max<node->val && r_min>node->val){
            int curr_sum=l_sum+r_sum+node->val;
            max_sum=max(max_sum,curr_sum);
            return {1,min(l_min,node->val), max(r_max,node->val),curr_sum};
        }
        else{
            return {0,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return max(0,max_sum);
    }
};