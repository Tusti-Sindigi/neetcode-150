#include <stdio.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    int carry=0, sum=0;
    struct ListNode *t1=l1, *t2=l2;

    struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    int s=t1->val+t2->val;
    
    temp->val=s%10+carry;
    temp->next=NULL;

    if(s>9)
        carry=1;

    struct ListNode *list=temp;

    t1=t1->next;
    t2=t2->next;

    while(t1 && t2)
    {
        s=t1->val+t2->val+carry;
        struct ListNode *newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=s%10;
        newNode->next=NULL;

        if(s>9)
            carry=1;
        else
            carry=0;

        t1=t1->next;
        t2=t2->next;
        temp->next=newNode;
        temp=newNode;
    } 

    while(t1)
    {
        s=t1->val+carry;
        struct ListNode *newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=s%10;
        newNode->next=NULL;

        if(s>9)
            carry=1;
        else
            carry=0;

        t1=t1->next;
        temp->next=newNode;
        temp=newNode;
    }   

    while(t2)
    {
        s=t2->val+carry;
        struct ListNode *newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=s%10;
        newNode->next=NULL;

        if(s>9)
            carry=1;
        else
            carry=0;

        t2=t2->next;
        temp->next=newNode;
        temp=newNode;
    }  

    if(carry)
    {
        struct ListNode *newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=1;
        newNode->next=NULL;

        temp->next=newNode;
        temp=newNode;
    }

    return list;
}