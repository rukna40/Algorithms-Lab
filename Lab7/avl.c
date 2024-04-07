#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int data;
}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int max(int a,int b){
    return a>b?a:b;
}

int height(node* root){
    if (root == NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

int bf(node* root){
    if (root == NULL)
        return 0;
    return height(root->left)-height(root->right);
}

node* lRot(node* x){
    node* y=x->right;
    x->right=y->left;
    y->left=x;
    return y;
}

node* rRot(node* x){
    node* y=x->left;
    x->left=y->right;
    y->right=x;
    return y;
}

node* lrRot(node* x){
    x->right=rRot(x->right);
    return lRot(x);
}

node* rlRot(node* x){
    x->left=lRot(x->left);
    return rRot(x);

}

node* createRec(node* root,int val){
    if (root==NULL){
        return createNode(val);
    }
    else if (val<root->data){
        root->left=createRec(root->left,val);
    }
    else if (val>root->data){
        root->right=createRec(root->right,val);
    }

    // return root;

    int bal = bf(root);
    if (bal>1 && val<root->left->data){
        return rRot(root);
    }
    if (bal<-1 && val>root->right->data){
        return lRot(root);
    }
    if (bal>1 && val>root->left->data){
        return rlRot(root);
    }
    if (bal<-1 && val<root->right->data){
        return lrRot(root);
    }
    return root;
}

void inorder(node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
} 

void preorder(node* root){
    if (root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
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
        root=createRec(root,x);
    }
    preorder(root);
    return 0; 
}