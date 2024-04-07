#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int s[MAX_SIZE];
    int top;
} stack;

typedef struct node {
    struct node *next;
    int data;
} node;

typedef struct {
    int n;
    int **adjMat;
    node **adjList;
} graph;

node *createNode(int x) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void addEdge(graph *g, int a, int b) {
    g->adjMat[a][b] = 1;
    node *newNode = createNode(b);
    newNode->next = g->adjList[a];
    g->adjList[a] = newNode;
}


int* dfs(int start, graph *g, int* visited) {
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    visited[start] = 1;
    printf("Visited %d \n", start);
    st->s[++st->top] = start;
    while (st->top > -1) {
        int ele = st->s[st->top--];
        for (int i = 0; i < g->n; i++) {
            if (g->adjMat[ele][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("Visited %d \n", i);
                st->s[++st->top] = i;
            }
        }
    }
}

int main() {
    graph *g = (graph *)malloc(sizeof(graph));
    g->n = 5;
    g->adjMat = (int **)malloc(g->n * sizeof(int *));
    g->adjList = (node **)malloc(g->n * sizeof(node*));

    for (int i = 0; i < g->n; i++) {
        g->adjMat[i] = (int *)calloc(g->n,sizeof(int));
        g->adjList[i] = NULL;
    }

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 3);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);

    int *visited = (int *)calloc(g->n,sizeof(int));

    dfs(0, g, visited);
    return 0;
}
