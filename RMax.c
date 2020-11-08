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
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
int RMax(struct Node *p)
{
    int x=0;
    if(p==0)
        return 0;
    x= RMax(p->next);
    //if (x>p->data)
      //  return x;
    //else return p->data;
    return x> p->data ? x:p->data; 
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    Display(first);
    printf("Max is %d\n",RMax(first));
    return 0;
}