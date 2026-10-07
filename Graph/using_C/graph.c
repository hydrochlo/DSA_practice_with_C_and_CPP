#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nodeid;
    int ns[100];
    int ncount;
};

struct Graph{
    struct Node *nodes[100];
    int nodecount;
} g;

void createnode(int n){
    int i=0;
    for(i=0; i<g.nodecount; i++){
        if(g.nodes[i]->nodeid == n) return;
    }

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->nodeid = n;
    newnode->ncount = 0;
    g.nodes[i] = newnode;
    g.nodecount++;
}

struct Node *getnode(int n){
    for(int i=0; i<g.nodecount; i++){
        if(g.nodes[i]->nodeid == n) return g.nodes[i];
    }

    return NULL;
}

void addneighbour(int nodeid, int nei){
    struct Node *p = getnode(nodeid);
    int i=0;

    for(i=0; i<p->ncount; i++){
        if(p->ns[i] == nei) return;
    }

    p->ns[i] = nei;
    p->ncount++;
}

void printgraph(){
    struct Node *p;

    for(int i=0; i<g.nodecount; i++){
        p = g.nodes[i];
        printf("\nNode %d: ", p->nodeid);
        
        for(int j=0; j<p->ncount; j++){
            printf("%d ",p->ns[j]);
        }
    }
}

void printpath(int *path, int pncount){
    printf("\nPath: ");
    for(int i=0; i<pncount; i++){
        printf("%d ", path[i]);
    }
}

int isinpath(int *path, int pncount, int n){
    for(int i=0; i<pncount; i++){
        if(path[i] == n) return 1;
    }
    return 0;
}

void findpath(int s, int d, int *path, int pncount){
    if(s == d){
        path[pncount] = s;
        pncount = pncount + 1;
        printpath(path, pncount);
        return;
    } else {
        int ip = isinpath(path, pncount, s);
        if(ip == 1) return;

        else {
            path[pncount] = s;
            pncount = pncount + 1;

            struct Node *p = getnode(s);
            for(int i=0; i<p->ncount; i++){
                int nei = p->ns[i];
                findpath(nei, d, path, pncount);
            }
        }
    }
}

void main(void){
    g.nodecount = 0;
    int edgecount, n1, n2;
    int path[100];

    scanf("%d", &edgecount);
    for(int i=0; i<edgecount; i++){
        scanf("%d%d", &n1, &n2);

        createnode(n1);
        createnode(n2);
        addneighbour(n1, n2);
        addneighbour(n2, n1);
    }

    printgraph();
    findpath(1, 10, path, 0);
}