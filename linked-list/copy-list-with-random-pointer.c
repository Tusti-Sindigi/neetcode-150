#include <stdio.h>

struct Node 
{
    int val;
    struct Node *next;
    struct Node *random;
};


struct Node* copyRandomList(struct Node* head) 
{
    if(head==NULL)
        return NULL;

    struct Node *temp=head, *curr=(struct Node*)malloc(sizeof(struct Node));

    curr->val=temp->val;
    curr->next=NULL;
    curr->random=NULL;

    temp=temp->next;

    struct Node *list=curr;

    while(temp)
    {
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

        newNode->val=temp->val;
        newNode->next=NULL;
        newNode->random=NULL;

        curr->next=newNode;
        curr=newNode;
        temp=temp->next;
    }

    struct Node *t=head, *l=list;

    while(t)
    {
        if(t->random==NULL)
            l->random=NULL;
        else
        {
            int rndm=t->random->val;
            struct Node *lst=list;

            struct Node *tmp=head;
            int count=0;
            
            while(tmp!=t->random)
            {
                count++;
                tmp=tmp->next;
            }

            while(count)
            {
                count--;
                lst=lst->next;
            }

            l->random=lst;
        }
        t=t->next;
        l=l->next;
    }
    return list;
}