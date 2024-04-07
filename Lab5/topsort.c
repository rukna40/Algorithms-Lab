#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
} node;

typedef struct
{
    int n;
    int **adjMat;
    node **adjList;
} graph;

typedef struct {
    int q[100];
    int front;
    int rear;
} queue;

typedef struct {
    int s[100];
    int top;
} stack;

node *createNode(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void addEdge(graph *g, int a, int b)
{
    g->adjMat[a][b] = 1;
    struct node *newNode = createNode(b);
    newNode->next = g->adjList[a];
    g->adjList[a] = newNode;
}

void topSortDfs(graph* g){
    int* indegree=(int*)calloc(g->n,sizeof(int));
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            if(g->adjMat[j][i]){
                indegree[i]++;
            }
        }
    }
    queue* qu=(queue*)malloc(sizeof(queue));    
    qu->front=0;
    qu->rear=0;
    for(int i=0;i<g->n;i++)
        if (indegree[i]==0)
            qu->q[qu->rear++]=i;
    while (qu->front!=qu->rear){
        int ele=qu->q[qu->front++];
        printf("%d\t",ele);
        for(int j=0;j<g->n;j++){
            if (g->adjMat[ele][j]){
                indegree[j]--;
                if (indegree[j]==0){
                    qu->q[qu->rear++]=j;
                }
            }
        }
    }
}

void topSortSrem(graph* g){
    int* indegree=(int*)calloc(g->n,sizeof(int));
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            if(g->adjMat[j][i]){
                indegree[i]++;
            }
        }
    }
    stack* st=(stack*)malloc(sizeof(stack));    
    st->top=-1;
    for(int i=0;i<g->n;i++)
        if (indegree[i]==0)
            st->s[++st->top]=i;
    while (st->top>-1){
        int ele=st->s[st->top--];
        printf("%d\t",ele);
        for(int j=0;j<g->n;j++){
            if (g->adjMat[ele][j]){
                indegree[j]--;
                if (indegree[j]==0){
                    st->s[++st->top]=j;
                }
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
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    topSortDfs(g);
    printf("\n");
    topSortSrem(g);

    return 0;
}