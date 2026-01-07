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
    using ll = long long;
    const int MOD = 1e9 + 7;
    ll maxProductValue = 0;
    ll totalSum = 0;

    // First DFS to compute total sum of tree
    ll computeTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + computeTotalSum(root->left) + computeTotalSum(root->right);
    }

    // Second DFS to compute subtree sums and maximize product
    ll dfs(TreeNode* root) {
        if (!root) return 0;
        ll subtreeSum = root->val + dfs(root->left) + dfs(root->right);
        // Consider splitting here
        ll product = subtreeSum * (totalSum - subtreeSum);
        maxProductValue = max(maxProductValue, product);
        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = computeTotalSum(root);
        dfs(root);
        return maxProductValue % MOD;
    }
};
