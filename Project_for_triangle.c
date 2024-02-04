/*#include <stdio.h>
int mynodes[50];
struct Node
{
    int nodeid;
    int adjcount;
    int adjs[10];
    int costs[10];
};

int addNode (struct Node * p, int nid, int count)
{
    int i =0, ncount = count;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid) { break; }
    }
    if (i == count)
    {
        mynodes[ncount] = nid;
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent (struct Node *p, int nid1, int nid2, int cost, int count)
{
    int i =0, index;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid1)
        {
            //int c = p[i].adjcount;
            p[i].adjs[p[i].adjcount] = nid2;
            p[i].costs[p[i].adjcount] = cost;
            p[i].adjcount ++;

            break;
        }
    }
}

int added (int * list, int lcount, int nid)
{
    int i =0;
    for (i=0;i<lcount;i++)
    {
        if (list[i] == nid) { return 1; }
    }
    return 0;
}



int main() {
    // Write C code here
    //printf("Hello world");

    struct Node nodes[50];
    int nodecount = 0;
    int n1=0, n2=0, c = 0;

    while (1)
    {
        printf ("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c== -9) {break;}
        nodecount = addNode (&nodes[0], n1, nodecount);
        nodecount = addNode (&nodes[0], n2, nodecount);

        addAdjacent (&nodes[0], n1, n2, c, nodecount);
        addAdjacent (&nodes[0], n2, n1, c, nodecount);
    }

       for(int i=0;i<nodecount;i++)
       {
           for(int j=0;j<nodes[i].adjcount;j++)
           {
               for(int k=j+1;k<nodes[i].adjcount;k++)
               {
                   for(int l=0;l<nodecount;l++)
                   {
                       if(nodes[l].nodeid==nodes[i].adjs[j])
                       {
                           for(int m=0;m<nodes[l].adjcount;m++)
                           {
                               if(nodes[l].adjs[m]==nodes[i].adjs[k])
                               {
                                   printf("%d %d %d\n",nodes[i].nodeid,nodes[i].adjs[j],nodes[i].adjs[k]);
                               }
                           }
                       }
                   }
               }
           }
       }

    return 0;
}*/


#include <stdio.h>
int mynodes[50];

struct Node
{
    int nodeid;
    int adjcount;
    int adjs[10];
    int costs[10];
};

int addNode(struct Node *p, int nid, int count)
{
    int i = 0, ncount = count;
    for (i = 0; i < count; i++)
    {
        if (p[i].nodeid == nid)
        {
            break;
        }
    }
    if (i == count)
    {
        mynodes[ncount] = nid;
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent(struct Node *p, int nid1, int nid2, int cost, int count)
{
    int i = 0, index;
    for (i = 0; i < count; i++)
    {
        if (p[i].nodeid == nid1)
        {
            p[i].adjs[p[i].adjcount] = nid2;
            p[i].costs[p[i].adjcount] = cost;
            p[i].adjcount++;

            break;
        }
    }
}

int added(int *list, int lcount, int nid)
{
    int i = 0;
    for (i = 0; i < lcount; i++)
    {
        if (list[i] == nid)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    // Write C code here
    //printf("Hello world");

    struct Node nodes[50];
    int nodecount = 0;
    int n1 = 0, n2 = 0, c = 0;

    while (1)
    {
        printf("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c == -9)
        {
            break;
        }
        nodecount = addNode(&nodes[0], n1, nodecount);
        nodecount = addNode(&nodes[0], n2, nodecount);

        addAdjacent(&nodes[0], n1, n2, c, nodecount);
        addAdjacent(&nodes[0], n2, n1, c, nodecount);
    }

    for (int i = 0; i < nodecount; i++)
    {
        for (int j = 0; j < nodes[i].adjcount; j++)
        {
            for (int k = j + 1; k < nodes[i].adjcount; k++)
            {
                int node1 = nodes[i].nodeid;
                int node2 = nodes[i].adjs[j];
                int node3 = nodes[i].adjs[k];

                int isTriangle = 0;

                for (int l = 0; l < nodecount; l++)
                {
                    if (nodes[l].nodeid == node2)
                    {
                        for (int m = 0; m < nodes[l].adjcount; m++)
                        {
                            if (nodes[l].adjs[m] == node3)
                            {
                                isTriangle = 1;
                                break;
                            }
                        }
                    }
                }

                if (isTriangle)
                {
                    printf("%d %d %d\n", node1, node2, node3);
                }
            }
        }
    }

    return 0;
}
