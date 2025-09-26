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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next) fast=head->next->next;
        else fast=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            if(fast->next) fast=fast->next->next;
            else fast=NULL;

        }
        if(slow->next) slow->next=slow->next->next;
        return head;
    }
};