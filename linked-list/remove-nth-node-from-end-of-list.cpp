#include <stdio.h>   //NULL, printf()
#include<stdlib.h>  //free()

struct ListNode 
{
    int val;
    struct ListNode *next;
 };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }    

    struct ListNode *temp=head;
    int count=1;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    count=count-n+1;

    if(count==1)
    {
        struct ListNode *tmp=head->next;
        free(head);
        return tmp;
    }

    struct ListNode *temp2=head, *prev=NULL;

    while(count!=1)
    {
        count--;
        prev=temp2;
        temp2=temp2->next;
    }

    prev=temp2->next;
    free(temp);

    return head;
}