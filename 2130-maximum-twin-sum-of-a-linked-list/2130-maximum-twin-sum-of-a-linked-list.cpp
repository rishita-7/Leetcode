/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        int max_sum=0;
        ListNode* curr=head;
        while(curr){
            values.push_back(curr->val);
            curr=curr->next;
        }
        int n=values.size();
        for(int i=0;i<n/2;i++){
            int curr_sum=values[i]+values[n-1-i];
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
    }
};