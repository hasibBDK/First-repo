#include<bits/stdc++.h>
using namespace std;
struct mine
{
    int a,b;
    struct mine * next;
};

int main()
{
    struct mine *p1,*p2;
    p1=(struct mine *)malloc(sizeof(struct mine));
    p1->a=40;
    p1->b=50;
    p1->next=NULL;
    p2=(struct mine *)malloc(sizeof(struct mine));
    p2->a=60;
    p2->b=70;
    p2->next=NULL;
    p1->next=p2;
    cout<<p1->a<<" "<<p1->b<<" "<<'\n'<<p2->a<<" "<<p2->b<<endl;

}


#include<bits/stdc++.h>
using namespace std;
struct fine
{
    int a,b;
    struct fine * next;
};
void welldone(struct fine *k)
{
 while(k!=NULL)
 {
    cout<<'\n'<<k->a<<'\n'<<k->b;
    k=k->next;
 }
}


int main()
{
    struct fine *k1,*k2,*k3,*k;
    k1=(struct fine *)malloc(sizeof(struct fine));
    k1->a=50;
    k1->b=60;
    k1->next=NULL;


    k2=(struct fine *)malloc(sizeof(struct fine));
    k2->a=70;
    k2->b=80;
    k2->next=NULL;

    k3=(struct fine *)malloc(sizeof(struct fine));
    k3->a=90;
    k3->b=100;
    k3->next=NULL;
    k1->next=k2;
    k2->next=k3;

    k=k1;
    welldone(k);
}


#include<bits/stdc++.h>
using namespace std;
struct hasib{
    int a,b;
    struct hasib * next;
};

int main()
{
    struct hasib *m1,*m2,*m3,*m;
    m1=(struct hasib *)malloc(sizeof(struct hasib));
    m1->a=48;
    m1->b=49;
    m1->next=NULL;
    m2=(struct hasib *)malloc(sizeof(struct hasib));
    m2->a=50;
    m2->b=51;
    m2->next=NULL;
    m3=(struct hasib *)malloc(sizeof(struct hasib));
    m3->a=52;
    m3->b=53;
    m3->next=NULL;
    m=m1;
    m1->next=m2;
    m2->next=m3;
    while(m!=NULL)
    {
        cout<<m->a<<'\n'<<m->b<<endl;
        m=m->next;
    }


}



//Take a input and print it 

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



