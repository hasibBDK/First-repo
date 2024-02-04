#include <stdio.h>
#include <stdbool.h>

int taken_nodes[100];

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
        taken_nodes[ncount] = nid;
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

bool isAlreadyPrinted(int node1, int node2, int node3, int *printedNodes, int printedCount)
{
    for (int i = 0; i < printedCount; i++)
    {
        if ((printedNodes[i] == node1 || printedNodes[i] == node2 || printedNodes[i] == node3) &&
            (printedNodes[i + 1] == node1 || printedNodes[i + 1] == node2 || printedNodes[i + 1] == node3) &&
            (printedNodes[i + 2] == node1 || printedNodes[i + 2] == node2 || printedNodes[i + 2] == node3))
        {
            return true; // Triangle already printed
        }
        i += 2; // Skip to the next triangle
    }
    return false; // Triangle not printed
}

void printTriangle(int node1, int node2, int node3, int *printedNodes, int *printedCount)
{
    printf("%d %d %d\n", node1, node2, node3);
    printedNodes[*printedCount] = node1;
    printedNodes[*printedCount + 1] = node2;
    printedNodes[*printedCount + 2] = node3;
    *printedCount += 3; // Increment printedCount by 3
}

int main()
{
    struct Node nodes[50];
    int nodecount = 0;
    int n1 = 0, n2 = 0, c = 0;
    int printedNodes[150]; // Array to store printed triangles
    int printedCount = 0; // Count of printed triangles

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
                for (int l = 0; l < nodecount; l++)
                {
                    if (nodes[l].nodeid == nodes[i].adjs[j])
                    {
                        for (int m = 0; m < nodes[l].adjcount; m++)
                        {
                            if (nodes[l].adjs[m] == nodes[i].adjs[k])
                            {
                                int node1 = nodes[i].nodeid;
                                int node2 = nodes[i].adjs[j];
                                int node3 = nodes[i].adjs[k];

                                if (!isAlreadyPrinted(node1, node2, node3, printedNodes, printedCount))
                                {
                                    printTriangle(node1, node2, node3, printedNodes, &printedCount);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
