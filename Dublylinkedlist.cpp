#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    struct node * next;
    struct node *prev;
};


int main()
{
  struct node *a,*b,*start,*end,*k,*midle;
  int m,i=0;
  while(1)
  {
   cout<<"m= ";
   cin>>m;
   if(m<0)
   {
    break;
   }
  k=(struct node*)malloc(sizeof(struct node));
  k->value=m;
  k->next=NULL;
  k->prev=NULL;
  if(i==0)
  {
  start=k;
  end=k;
  }
  else 
  {
    end->next=k;
    k->prev=end;
    end=k;
    if(i==3)
    midle=k;
  }

  i++;

  }
  k=start;
   while(k!=NULL)
   {
    cout<<k->value<<" ";
    k=k->next;
   }
cout<<"\n";
k=end;
  while(k!=NULL)
  {
    cout<<k->value<<" ";
    k=k->prev;
    //cout<<"\n";
   }



}