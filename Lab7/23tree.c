#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* mid;
    struct node* right;
    int a;
    int b;
}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->a = data;
    newNode->b = 0;
    newNode->left = NULL;
    newNode->mid = NULL;
    newNode->right = NULL;
    return newNode;
}

node* splitNode(node* root, int val){

}

node* createTree(node* root, int val){
    if (root==NULL)
        return createNode(val);
    if (root->b == 0){ 
        if(val>root->a){
            root->b = val;
        }
        else{
            root->b=root->a;
            root->a = val;
        }        
    }
    else if (root->b != 0) {
        root=splitNode(root, val);
    }
    else{
        if (val<root->a){
            root->left=createTree(root->left,val);
        }
        else if (val>root->a && val<root->b){
            root->mid=createTree(root->mid,val);
        }
        else if (val>root->b){
            root->right=createTree(root->right,val);
        }
    }

    return root;
}

void preorder(node* root){
    if (root!=NULL){
        printf("%d\t",root->a);
        if (root->b != 0){
            printf("%d\t", root->b);
        }
        preorder(root->left);
        preorder(root->mid);
        preorder(root->right);
    }
} 

int main(){
    int x; 
    node* root=NULL;
    while(1){
        printf("Enter value (-1 to exit): ");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        root=createTree(root,x);
    }
    preorder(root);
    return 0; 
}