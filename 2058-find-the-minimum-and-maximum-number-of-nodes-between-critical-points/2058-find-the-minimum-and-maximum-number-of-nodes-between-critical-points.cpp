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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1;
        int f_idx=-1;
        int s_idx=-1;
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;
        if(c==NULL)
            return {-1,-1};
        while(c){
            //Finding the first and the last critical points
            if((b->val > a->val && b->val > c->val)|| (b->val < a->val && b->val < c->val)){
                if(f_idx==-1)
                    f_idx=idx;
                else
                    s_idx=idx;
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        if(s_idx==-1) //second critical point not found
            return {-1,-1};
        int max_dist=s_idx-f_idx;
        int min_dist=INT_MAX;
        //Finding the minimum distance
        f_idx=-1;
        s_idx=-1;
        idx=1;
        a=head;
        b=head->next;
        c=head->next->next;
        while(c){
            if((b->val > a->val && b->val > c->val)|| (b->val < a->val && b->val < c->val)){
                f_idx=s_idx;
                s_idx=idx;
                if(f_idx!=-1){
                    min_dist=min(min_dist,s_idx-f_idx);
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        return {min_dist,max_dist};       
    }
};