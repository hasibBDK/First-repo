/*#include <stdio.h>

int mynodes[50];

struct Node {
    int nodeid;
    int adjcount;
    int adjs[10];
    int costs[10];
};

struct Triangle {
    int node1;
    int node2;
    int node3;
};

int addNode(struct Node *p, int nid, int count) {
    int i = 0, ncount = count;
    for (i = 0; i < count; i++) {
        if (p[i].nodeid == nid) {
            break;
        }
    }
    if (i == count) {
        mynodes[ncount] = nid;
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent(struct Node *p, int nid1, int nid2, int cost, int count) {
    int i = 0, index;
    for (i = 0; i < count; i++) {
        if (p[i].nodeid == nid1) {
            p[i].adjs[p[i].adjcount] = nid2;
            p[i].costs[p[i].adjcount] = cost;
            p[i].adjcount++;
            break;
        }
    }
}

int added(int *list, int lcount, int nid) {
    int i = 0;
    for (i = 0; i < lcount; i++) {
        if (list[i] == nid) {
            return 1;
        }
    }
    return 0;
}

int isTriangle(struct Triangle *triangles, int triangleCount, int node1, int node2, int node3) {
    for (int i = 0; i < triangleCount; i++) {
        if ((triangles[i].node1 == node1 || triangles[i].node1 == node2 || triangles[i].node1 == node3) &&
            (triangles[i].node2 == node1 || triangles[i].node2 == node2 || triangles[i].node2 == node3) &&
            (triangles[i].node3 == node1 || triangles[i].node3 == node2 || triangles[i].node3 == node3)) {
            return 1; // Triangle already exists
        }
    }
    return 0; // Triangle does not exist
}

void addTriangle(struct Triangle *triangles, int *triangleCount, int node1, int node2, int node3) {
    triangles[*triangleCount].node1 = node1;
    triangles[*triangleCount].node2 = node2;
    triangles[*triangleCount].node3 = node3;
    (*triangleCount)++;
}

int main() {
    struct Node nodes[50];
    int nodecount = 0;
    int n1 = 0, n2 = 0, c = 0;
    struct Triangle triangles[50];
    int triangleCount = 0;

    while (1) {
        printf("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c == -9) {
            break;
        }
        nodecount = addNode(&nodes[0], n1, nodecount);
        nodecount = addNode(&nodes[0], n2, nodecount);

        addAdjacent(&nodes[0], n1, n2, c, nodecount);
        addAdjacent(&nodes[0], n2, n1, c, nodecount);
    }

    for (int i = 0; i < nodecount; i++) {
        for (int j = 0; j < nodes[i].adjcount; j++) {
            for (int k = j + 1; k < nodes[i].adjcount; k++) {
                for (int l = 0; l < nodecount; l++) {
                    if (nodes[l].nodeid == nodes[i].adjs[j]) {
                        for (int m = 0; m < nodes[l].adjcount; m++) {
                            if (nodes[l].adjs[m] == nodes[i].adjs[k]) {
                                int node1 = nodes[i].nodeid;
                                int node2 = nodes[i].adjs[j];
                                int node3 = nodes[i].adjs[k];

                                if (!isTriangle(triangles, triangleCount, node1, node2, node3)) {
                                    printf("Triangle: %d %d %d\n", node1, node2, node3);
                                    addTriangle(triangles, &triangleCount, node1, node2, node3);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}*/


/*#include <stdio.h>

struct Node {
    int nodeid;
    int adjcount;
    int adjs[10];
    int costs[10];
};

int addNode(struct Node *p, int nid, int count) {
    int i = 0, ncount = count;
    for (i = 0; i < count; i++) {
        if (p[i].nodeid == nid) {
            break;
        }
    }
    if (i == count) {
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent(struct Node *p, int nid1, int nid2, int cost, int count) {
    int i = 0, index;
    for (i = 0; i < count; i++) {
        if (p[i].nodeid == nid1) {
            int c = p[i].adjcount;
            p[i].adjs[c] = nid2;
            p[i].costs[c] = cost;
            p[i].adjcount = c + 1;

            break;
        }
    }
}

int added(int *list, int lcount, int nid) {
    int i = 0;
    for (i = 0; i < lcount; i++) {
        if (list[i] == nid) {
            return 1;
        }
    }
    return 0;
}

void findpath(struct Node *p, int count, int start, int end, int *list, int *clist, int lcount) {
    int index = 0, i = 0;

    // Check if list contains the end node
    if (list[lcount - 1] == end) {
        int tcost = 0;
        printf("\n");
        for (i = 0; i < lcount; i++) {
            printf(" %d ", list[i]);
            tcost += clist[i];
        }
        printf(" cost = %d", tcost);

        // Check if the path forms a triangle (contains exactly 3 nodes)
        if (lcount == 3) {
            printf(" (Triangle)");
        }

        return;
    }

    for (i = 0; i < count; i++) {
        if (p[i].nodeid == start) {
            index = i;
            break;
        }
    }

    for (i = 0; i < p[index].adjcount; i++) {
        int a = added(list, lcount, p[index].adjs[i]);
        if (a == 0) {
            list[lcount] = p[index].adjs[i];
            clist[lcount] = p[index].costs[i];
            lcount++;

            findpath(p, count, p[index].adjs[i], end, list, clist, lcount);
            lcount--;
        }
    }
}

int main() {
    struct Node nodes[50];
    int nodecount = 0;
    int n1 = 0, n2 = 0, c = 0;

    while (1) {
        printf("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c == -9) {
            break;
        }
        nodecount = addNode(&nodes[0], n1, nodecount);
        nodecount = addNode(&nodes[0], n2, nodecount);

        addAdjacent(&nodes[0], n1, n2, c, nodecount);
        addAdjacent(&nodes[0], n2, n1, c, nodecount);
    }

    int start, end;
    printf("start, end ? ");
    scanf("%d %d", &start, &end);
    int list[50], clist[50], lcount = 0;
    list[0] = start;
    clist[0] = 0;
    lcount = 1;

    findpath(nodes, nodecount, start, end, list, clist, lcount);

    return 0;
}
*/
#include <stdio.h>
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
}