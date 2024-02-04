#include <stdio.h>
#include <stdbool.h>

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

bool isCircularPath(struct Node *p, int count, int start, int current, int *visited)
{
    visited[current] = 1;

    for (int i = 0; i < p[current].adjcount; i++)
    {
        int next = p[current].adjs[i];

        if (next == start && visited[start] == 1)
        {
            return true; // Found a circular path
        }

        if (visited[next] == 0)
        {
            if (isCircularPath(p, count, start, next, visited))
            {
                return true; // Circular path found in a recursive call
            }
        }
    }

    visited[current] = 0; // Backtrack
    return false;
}

void detectcircles(struct Node *p, int count)
{
    int visited[50] = {0}; // Initialize visited array
    bool foundCircle = false;

    for (int i = 0; i < count; i++)
    {
        if (isCircularPath(p, count, i, i, visited))
        {
            printf("Circular Path starting from node %d: ", i);
            foundCircle = true;
            for (int j = 0; j < count; j++)
            {
                if (visited[j] == 1)
                {
                    printf("%d ", j);
                }
            }
            printf("%d\n", i); // Print the starting node again to complete the circle
        }
        visited[i] = 0; // Reset visited array for the next iteration
    }

    if (!foundCircle)
    {
        printf("No circular paths found in the graph.\n");
    }
}

int main()
{
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

    detectcircles(nodes, nodecount);

    return 0;
}
