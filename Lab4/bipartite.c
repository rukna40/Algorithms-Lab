#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    struct node* next;
    int data;
} node;

typedef struct {
    int** adjMat;
    node** adjList;
    int n;
} graph;

typedef struct {
    int s[MAX_SIZE];
    int top;
} stack;

typedef struct {
    int q[MAX_SIZE];
    int front;
    int rear;
} queue;


node* createNode(int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void addEdge(graph* g, int s, int e) {
    g->adjMat[s][e] = 1;
    g->adjMat[e][s] = 1;
    node* new = createNode(e);
    new->next = g->adjList[s];
    g->adjList[s] = new;

    new = createNode(s);
    new->next = g->adjList[e];
    g->adjList[e] = new;
}

int bfsBipartite(graph* g, int start, int* visited, int* colors) {
    queue *qu = (queue*)malloc(sizeof(queue));
    qu->front = 0;qu->rear=0;
    qu->q[qu->rear++] = start;
    visited[start] = 1;
    colors[start] = 0;
    while (qu->front!=qu->rear) {
        int ele = qu->q[qu->front++];
        for (int i = 0; i < g->n; i++) {
            if (g->adjMat[ele][i] == 1) {
                if (visited[i] == 0) {
                    visited[i] = 1;
                    colors[i] = 1 - colors[ele];
                    qu->q[qu->rear++] = i;
                }
                else if (colors[i] == colors[ele]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int dfsBipartite(graph* g, int start, int* visited, int* colors) {
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    st->s[++st->top] = start;
    visited[start] = 1;
    colors[start] = 0;
    while (st->top > -1) {
        int ele = st->s[st->top--];
        for (int i = 0; i < g->n; i++) {
            if (g->adjMat[ele][i] == 1) {
                if (visited[i] == 0) {
                    visited[i] = 1;
                    colors[i] = 1 - colors[ele];
                    st->s[++st->top] = i;
                }
                else if (colors[i] == colors[ele]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    graph* g = (graph*)malloc(sizeof(graph));
    g->n = 8;
    g->adjMat = (int**)malloc(g->n * sizeof(int*));
    g->adjList = (node**)malloc(g->n * sizeof(node*));

    for (int i = 0; i < g->n; i++) {
        g->adjMat[i] = (int*)calloc(g->n, sizeof(int));
        g->adjList[i] = NULL;
    }

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 2, 6);
    addEdge(g, 3, 7);
    addEdge(g, 4, 7);
    addEdge(g, 5, 7);
    addEdge(g, 6, 7);

    int* visited = (int*)calloc(g->n, sizeof(int));
    int* colors = (int*)calloc(g->n, sizeof(int));

    if (dfsBipartite(g, 0, visited, colors)) {
        printf("Graph is bipartite\n");
    }
    else {
        printf("Graph is not bipartite\n");
    }

    if (bfsBipartite(g, 0, visited, colors)) {
        printf("Graph is bipartite\n");
    }
    else {
        printf("Graph is not bipartite\n");
    }
    return 0;
}
