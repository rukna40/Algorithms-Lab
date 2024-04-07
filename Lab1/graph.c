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

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->n = 3; 
    g->adjMat = (int **)malloc(g->n * sizeof(int *));
    g->adjList = (node **)malloc(g->n * sizeof(node*));
    
    for (int i = 0; i < g->n; i++){
        g->adjMat[i] = (int *)malloc(g->n * sizeof(int));
        g->adjList[i] = NULL;
        for (int j = 0; j < g->n; j++)
        {
            g->adjMat[i][j] = 0;
        }
    }
    
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    
    for (int i = 0; i < g->n; i++)
    {
        node *temp = g->adjList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (temp!=NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
