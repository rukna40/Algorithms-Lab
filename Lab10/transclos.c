#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 9999999999

typedef struct node{
    struct node* next;
    int data;
}node;


typedef struct{
    int v;
    // node** adjlist;  
    int** adjmat;
}graph;


node* createNode(int x){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void addEdge(graph* g, int a,int b, int w){
    g->adjmat[a][b]=w;
    // node *newNode = createNode(b);
    // newNode->next = g->adjlist[a];
    // g->adjlist[a]=newNode;    
}

void floyd(graph* g){
    int** mat=g->adjmat;
    
    for(int i=0;i<g->v;i++){
        for(int j=0;j<g->v;j++){
            for(int k=0;k<g->v;k++){
                if (mat[i][j]>mat[i][k] + mat[k][j]){
                    mat[i][j]=mat[i][k] + mat[k][j];
                }
            }
        }
    }
    for(int i=0;i<g->v;i++){
        for(int j=0;j<g->v;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->v = 3; 
    g->adjmat = (int **)malloc(g->v * sizeof(int *));
    // g->adjlist = (node **)malloc(g->v * sizeof(node*));
    
    for (int i = 0; i < g->v; i++){
        g->adjmat[i] = (int *)malloc(g->v * sizeof(int));
        // g->adjlist[i] = NULL;
        for (int j = 0; j < g->v; j++)
        {
            g->adjmat[i][j] = 0;
        }
    }
    
    addEdge(g, 0, 1, 2);
    addEdge(g, 0, 2, 4);
    addEdge(g, 1, 2, 2);
    addEdge(g, 1, 0, 6);
    addEdge(g, 2, 0, 1);
    addEdge(g, 2, 1, 4);


    floyd(g);

    return 0;
}
