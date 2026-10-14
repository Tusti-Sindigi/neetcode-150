#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head) 
{
    struct ListNode *t=head;

    if(t!=NULL && t->next!=NULL)
    {
        while(t->next!=NULL && t->next->next!=NULL)
        {
            struct ListNode *curr=t->next, *prev=NULL;
            
            while(curr)
            {
                struct ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            t->next=prev;
            t=t->next;
        }
    }
}