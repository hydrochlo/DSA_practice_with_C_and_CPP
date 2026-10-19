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

void createnode(int n){ // n:2
    int i=0;
    // g.nodecount = 1
    for(i=0; i<g.nodecount; i++){ // 1 < 1; False; i=1;
        if(g.nodes[i]->nodeid == n) {
            return;
        }
    }

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    g.nodes[i] = newnode; // g.nodes[1] = newnode;
    newnode->nodeid = n; // newnode->nodeid = 2
    newnode->ncount = 0; // newnode->ncount = 0
    g.nodecount++; // g.nodecount = 2
}

struct Node *getnode(int n){

    for(int i=0; i < g.nodecount; i++){ // g.nodecount = 2
        if(g.nodes[i]->nodeid == n) {
            return g.nodes[i];
        }
    }

    return NULL;
}

void addneighbour(int nodeid, int nei){ // nodeid:1, nei:2
    struct Node *p = getnode(nodeid); // getnode(1)
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
    for(int i=0; i<pncount; i++){ // path = [1] // pncount = 1
        if(path[i] == n) return 1; // path[0] = 1, 1==2 -> False
    }
    return 0;
}

void findpath(int s, int d, int *path, int pncount){
    if(s == d){ // s=1, d=5
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
            for(int i=0; i<p->ncount; i++){ //p->ncount = 2
                int nei = p->ns[i]; // nei = 2
                findpath(nei, d, path, pncount); // findpath(2, 5, [1], 1)
            }
        }
    }
}

int main(){
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

    // printgraph();
    findpath(1, 5, path, 0);
    return 0;
}