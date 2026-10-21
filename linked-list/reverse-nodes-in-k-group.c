#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    struct ListNode *temp=head;
    int c=0;

    while(temp)
    {
        c++;
        temp=temp->next;
    }

    int count=c/k;

    struct ListNode *curr=head, *end=curr, *list=NULL;

    while(count--)
    {
        int i=k;
        struct ListNode *start=curr, *prev=NULL;

        while(i--)
        {
            struct ListNode *t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }

        if(count+1==c/k)
            list=prev;
        else
        {
            end->next=prev;
            end=start;
        }

        end->next=curr;
    }
    return list;
}