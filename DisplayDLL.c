#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first=NULL;
void create(int A[], int n)
{
    struct Node *t,*last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
int Length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    printf("\nLength is :%d\n",Length(first));
    Display(first);
    return 0;

}