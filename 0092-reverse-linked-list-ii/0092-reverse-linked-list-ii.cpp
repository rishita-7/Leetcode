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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==nullptr || left==right)
            return head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* pre=dummy;
        for(int i=0;i<left-1;i++)
            pre=pre->next;   //pre points to the node just before the reversal section
        ListNode* p=pre;
        ListNode* q= pre->next ;//first node of the reversal section
        //reverse the required section
        ListNode* curr=q;
        ListNode* previous=p; //this will act as the dummy node of the reversal
        for(int i=0;i<right-left+1;i++){
            ListNode * nextNode=curr->next;
            curr->next=previous;
            previous=curr;
            curr=nextNode;
        }
        p->next=previous;
        q->next=curr;
        return dummy->next;
    }
};