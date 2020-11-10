#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head; 
    last=Head;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *h)
{
    do
    {
        printf("%d\t",h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    Display(Head);
    return 0;
}