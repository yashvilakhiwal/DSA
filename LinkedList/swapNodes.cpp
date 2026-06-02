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
    int getSize(ListNode* head)
    {
        int size=0;
        while(head!=NULL)
        {
            size++;
            head=head->next;
        }
        return size;
    }
    ListNode* KthFromEnd(ListNode* head,int k)
    {
        ListNode* temp=head;
        int size=getSize(head);
        for(int i=0;i<size-k;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left=head;
        for(int i=0;i<k-1;i++)
        {
            left=left->next;
        }
        ListNode* right=KthFromEnd(head,k);
        int temp=left->val;
        left->val=right->val;
        right->val=temp;
        return head;
    }
};