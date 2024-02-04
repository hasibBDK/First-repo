#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node * next;
    node *prev;
    node(int vall)
    {
        value=vall;
        next=NULL:
        prev=NULL;
    }
};




//take a number to make a linked list
#include<bits/stdc++.h>
using namespace std;
struct moon{
    int value;
    struct moon *next;
};

int main()
{
    struct moon *m,*start,end; 
    int a,y=0;
    while(1)
    {
      cout<<"a = ";
      cin>>a;
      if(a==-1)
      break;
        m=(struct moon*)malloc(sizeof(struct moon));
        m->value=a;
        m->next=NULL:
    if(y==0)
    {
        start=m;
        end=m;
    }
    else{
        end->next=m;
        end=m;
    }
    y++;
    }

   while(m!=NULL)
   {
    cout<<m<<endl;
    m=m->next;
   }


    

}