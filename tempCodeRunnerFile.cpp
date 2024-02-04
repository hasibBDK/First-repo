#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    struct node * next;
};
int main()
{
    struct node *p1,*p2,*p3,*start,*end,*m;
    int a,b=0;
    while(1)
    {
        cout<<"a = ";
        cin>>a;
         if(a==-1)
         break;
        m=(struct node*)malloc(sizeof(struct node));
        m->value=a;
        m->next=NULL;
        if(b==0)
        {
            start=m;
            end=m;
        }
        else
        {
            end->next=m;
            end=m;
        }
        b++;
    }
    m=start;
    while(m!=NULL)
    {
        cout<<m->value<<'\n';
        m=m->next;
    }
}



