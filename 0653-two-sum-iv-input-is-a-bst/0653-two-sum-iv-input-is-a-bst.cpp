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
    stack<TreeNode*> asc;
    stack<TreeNode*>desc;
    TreeNode* getSmall(){
        if(asc.empty())
            return nullptr;
        TreeNode* small=asc.top();
        asc.pop();
        TreeNode* rightChild=small->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild=rightChild->left;
        }
        return small;
    }
    TreeNode* getLarge(){
        if(desc.empty())
            return nullptr;
        TreeNode* large=desc.top();
        desc.pop();
        TreeNode* leftChild=large->left;
        while(leftChild){
                desc.push(leftChild);
                leftChild=leftChild->right;
        }
        return large;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        TreeNode* t=root;
        while(t){
            asc.push(t);
            t=t->left;
        }
        t=root;
        while(t){
            desc.push(t);
            t=t->right;
        }
        TreeNode* i=getSmall();
        TreeNode* j=getLarge();
        while(i && j && i->val < j->val){
            if(i->val+ j->val ==k)
                return true;
            else if((i->val+j->val)<k)
                i=getSmall();
            else
                j=getLarge();
        }
        return false;
    }
};