#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int data;    
}node;

node* createNode(int x){
    node* new=(node*)malloc(sizeof(node));
    new->left=NULL;
    new->right=NULL;
    new->data=x;
    return new;
}

node* insert(node* root,int n){ 
    if (root==NULL)
        return createNode(n);
    else{
        if(root->data<n)
            root->right=insert(root->right,n);
        else if(root->data>n)
            root->left=insert(root->left,n);
    }
    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int total(node* root){
    static int count=0;
    if(root){
        total(root->left);
        count++;
        total(root->right);
    }
    return count;
}

int main() {
    int n=0;
    node* root=NULL;
    root = insert(root, 10);
    while(1){
        printf("Enter value: ");
        scanf("%d",&n);
        if (n==-1)
            break;
        insert(root,n);
    }
    inorder(root);
    printf("\n%d\n",total(root));

    return 0;
}