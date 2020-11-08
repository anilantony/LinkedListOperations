#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int sum(struct Node *p)
{
   int s=0;
    while(p!=NULL)
    {
        s+=p->data;// s=s+p->data
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p)
{
    if (p==0)
        return 0;
    else 
        return Rsum(p->next)+p->data;
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("Sum is %d\n\n",sum(first));
    printf("RSum is %d\n\n",Rsum(first));
}