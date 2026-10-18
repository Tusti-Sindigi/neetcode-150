#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head) 
{
    struct ListNode *slow=head, *fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    struct ListNode *second=slow->next, *prev=slow->next=NULL;

    while(second!=NULL)
    {
        struct ListNode *temp=second->next;
        second->next=prev;
        prev=second;
        second=temp;
    }

    struct ListNode *first=head;
    second=prev;

    while(second!=NULL)
    {
        struct ListNode *temp1=first->next, *temp2=second->next;

        first->next=second;
        second->next=temp1;

        first=temp1;
        second=temp2;
    }
}