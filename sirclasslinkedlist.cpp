Simple linked list example.
#include <stdio.h>

struct Test
{
    int a, b;
   
    struct Test * next;
};

int main() {
    struct Test *p1, *p2, *p3, *p4, *p;
   
    p1 = (struct Test *) malloc (sizeof (struct Test));
   
    p1->a = 10;
    p1->b = 20;
    p1->next = NULL;
   
   
    p2 = (struct Test *) malloc (sizeof (struct Test));
    p2->a = 50;
    p2->b = 60;
    p2->next = NULL;
   
    p1->next = p2;
   
    printf ("p1: %d %d ", p1->a, p1->b);
    printf ("\np2: %d %d ", p2->a, p2->b);
   

    return 0;
}



//new
Simple linked list example.

// Online C compiler to run C program online
#include <stdio.h>

struct Test
{
    int a, b;
   
    struct Test * next;
};

int main() {
    struct Test *p1, *p2, *p3, *p4, *p;
   
    p1 = (struct Test *) malloc (sizeof (struct Test));
   
    p1->a = 10;
    p1->b = 20;
    p1->next = NULL;
   
   
    p2 = (struct Test *) malloc (sizeof (struct Test));
    p2->a = 50;
    p2->b = 60;
    p2->next = NULL;
   
    p1->next = p2;
   
    printf ("p1: %d %d ", p1->a, p1->b);
    printf ("\np2: %d %d ", p2->a, p2->b);
   

    return 0;
}

//new
#include <stdio.h>

struct Test
{
    int a, b;
   
    struct Test * next;
};


void printlist (struct Test * p)
{
    while (p != NULL)    
    {
        printf ("\na = %d  b = %d", p->a, p->b);
        p = p->next;
    }    
}

int main() {
    struct Test *p1, *p2, *p3, *p4, *p;
   
    p1 = (struct Test *) malloc (sizeof (struct Test));
   
    p1->a = 10;
    p1->b = 20;
    p1->next = NULL;
   
   
    p2 = (struct Test *) malloc (sizeof (struct Test));
    p2->a = 50;
    p2->b = 60;
    p2->next = NULL;
   
   
   
    p3 = (struct Test *) malloc (sizeof (struct Test));
    p3->a = 60;
    p3->b = 70;
    p3->next = NULL;    
   
    p1->next = p2;
    p2->next = p3;
   
    p = p1;
   
    printlist (p);



   

    return 0;
}


//new

#include <stdio.h>
#include <stdlib.h>

struct Test
{
    int a, b;
    struct Test * next;
};


void printlist (struct Test * p)
{
    while (p != NULL)    
    {
        printf ("\na = %d  b = %d", p->a, p->b);
        p = p->next;
    }    
}

int main() {
    struct Test *p, *head, *current;
    int i;

    for (i=1;i<5;i++)
    {
        p = (struct Test *) malloc (sizeof (struct Test));
        scanf ("%d %d", &p->a, &p->b);
        p->next = NULL;
       
        if (i == 1) { head = p; current = p; }
        else { current->next = p; current = p; }
    }
   
   
    printlist (head);

    return 0;
}



//linked list

// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Test
{
    int a, b;
    struct Test * next;
};


void addnode (struct Test * p, int v1, int v2)
{
    struct Test *node = (struct Test *) malloc (sizeof (struct Test));
   
    while (p->next != NULL)    
    {
        p = p->next;
    }    
    node->a = v1;
    node->b = v2;
    node->next = NULL;
    p->next = node;
   
}


void printlist (struct Test * p)
{
    while (p != NULL)    
    {
        printf ("\na = %d  b = %d", p->a, p->b);
        p = p->next;
    }    
}

int main() {
    struct Test *p, *current;
    int i;

    struct Test *head = (struct Test *) malloc (sizeof (struct Test));
    head->a = 1;
    head->b = 2;
    head->next = NULL;
   
    addnode (head, 3, 4);
    addnode (head, 5, 6);
    addnode (head, 7, 8);
    addnode (head, 9, 10);
   
    printlist (head);

    return 0;
}   
