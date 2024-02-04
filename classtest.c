//student id -220227
#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};

int main()
{
    struct node *start,*end,*k,*head,*tail;
    head=NULL;
    tail==NULL;
    while(1)
    {
     printf("n = ");
    scanf("%d",&n);
    if(n==-99)
    break;
    if(n%2==0 && n>0)

    k = (struct node *)malloc(sizeof(struct node));
    k->value=n;
    k->next=NULL;
    if(m==0)
    {
        start = k;
        end = k;
    }
    else 
    {
        end->next = k;
        end = k;
    }
    m++;

}


for(struct node *i = start;i!= NULL; i = i->next;)
 {
    // for( struct node *j = i->next; j!= NULL; j = j->next)
    // {
        if(i->value<0)
        {
            =i->value;
        }
    
 }


k = start;
 

 while(k!=NULL)
 {
  printf("%d ",k->value);
  k=k->next;
 }
}












// int temp = i->value;
//             i->value = j->value;
//             j->value = temp;