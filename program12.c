#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct node {
    int data;
    int status;
    struct node *next, *point;
} node;
typedef struct topsort {
    int n;
    struct topsort *next;
} topsort;
node *g = NULL;
topsort *sort = NULL;
int time = 0;
int d[SIZE], f[SIZE];
node *q[SIZE];
int front = 0, rear = 0;
void addvertex(int n) {
    node *t = (node *)malloc(sizeof(node));
    t->data = n;
    t->status = 0;
    t->point = NULL;
    t->next = g;
    g = t;
}
node *find(int n) {
    node *t = g;
    while (t && t->data != n)
        t = t->next;
    return t;
}
void addedge(int u, int v) {
    node *v1 = find(u);
    node *v2 = find(v);

    node *t = (node *)malloc(sizeof(node));
    t->data = 0;
    t->status = 0;
    t->next = v1->point;
    t->point = v2;
    v1->point = t;
}

int emptyq() {
    return front == rear;
}

void enque(node *s) {
    int r1 = (rear + 1) % SIZE;
    if (r1 == front) {
        printf("\nQueue full!");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

node *deque() {
    if (emptyq()) {
        printf("\nQueue empty!");
        exit(2);
    }
    front = (front + 1) % SIZE;
    return q[front];
}

void topsorting(int n) {
    topsort *z = (topsort *)malloc(sizeof(topsort));
    z->n = n;
    z->next = sort;
    sort = z;
}

void topsortout() {
    while (sort) {
        printf("%d ", sort->n);
        sort = sort->next;
    }
}

void dfs_visit(node *u) {
    node *t;

    u->status = 1;
    printf("%d ", u->data);

    time++;
    d[u->data] = time;

    t = u->point;
    while (t) {
        node *v = t->point;
        if (v->status == 0)
            dfs_visit(v);
        t = t->next;
    }
time++;
f[u->data] = time;

    topsorting(u->data);
}

void dfs(node *start) {
    node *t = g;
    while (t) {
        t->status = 0;
        t = t->next;
    }
    dfs_visit(start);
}

void bfs(node *s) {
    node *t, *v;

    node *u = g;
    while (u) {
        u->status = 0;
        u = u->next;
    }

    printf("%d ", s->data);
    s->status = 1;

    enque(s);

    while (!emptyq()) {
        u = deque();

        t = u->point;
        while (t) {
            v = t->point;
            if (v->status == 0) {
                printf("%d ", v->data);
                v->status = 1;
                enque(v);
            }
            t = t->next;
        }
    }
}


int main() {
    addvertex(1);
    addvertex(2);
    addvertex(3);
    addvertex(4);
    addvertex(5);

    addedge(1, 2);
    addedge(1, 4);
    addedge(2, 3);
    addedge(2, 4);
    addedge(4, 3);
    addedge(4, 5);

    printf("\nDFS Traversal: ");
    dfs(find(1));

    printf("\nBFS Traversal: ");
    bfs(find(1));

    printf("\nTopological Sort Order: ");
    topsortout();

    return 0;
}

