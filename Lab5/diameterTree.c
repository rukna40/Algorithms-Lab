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

int max(int a,int b){
    return a>b?a:b;
}

int height(node* root){
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

int diameter(node* root){
    if (root==NULL)
        return 0;

    int lheight=height(root->left);
    int rheight=height(root->right);

    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);

    return max(1+lheight+rheight,max(ldiameter,rdiameter));
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
    printf("\n%d\n",diameter(root));

    return 0;
}