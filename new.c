//student id-220227
/*#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* addEven(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);
    if (tail == NULL) {
        return newNode;
    }
    tail->next = newNode;
    return newNode;
}

struct Node* addOdd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    return newNode;
}

struct Node* addNegative(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data >= 0) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayNegativeNumbers(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data < 0) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

void displayPositiveEvens(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > 0 && current->data % 2 == 0) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

void displayPositiveOdds(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > 0 && current->data % 2 != 0) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

int countEvens(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > 0 && current->data % 2 == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int countOdds(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > 0 && current->data % 2 != 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int countNegatives(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data < 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head,*tail;
    head=NULL;
    tail=NULL;

    int n;
    scanf("%d", &n);

    while (n != -99) {
        if (n % 2 == 0 && n > 0) {
            tail = addEven(tail, n);
            if (head == NULL) {
                head = tail;
            }
        } else if (n % 2 != 0 && n > 0) {
            head = addOdd(head, n);
        } else {
            head = addNegative(head, n);
        }
        scanf("%d", &n);
    }

    printf("Whole List:\n");
    display(head);

    printf("Negative Numbers:\n");
    displayNegativeNumbers(head);

    printf("Positive Evens:\n");
    displayPositiveEvens(head);

    printf("Positive Odds:\n");
    displayPositiveOdds(head);

    printf("Count of Positive Evens: %d\n", countEvens(head));
    printf("Count of Positive Odds: %d\n", countOdds(head));
    printf("Count of Negative Numbers: %d\n", countNegatives(head));

    freeLinkedList(head);
    return 0;
}*/

#include <stdio.h>

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
}
