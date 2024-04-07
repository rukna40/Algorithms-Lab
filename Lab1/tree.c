#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *lchild;
    struct node *rchild;   
    int data; 
} node;

node* createNode(int x){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->lchild=NULL;
    newnode->rchild=NULL; 
    return newnode;
} 

void createBST(node** root){
    int x = 0; 
    while(1){
        printf("Enter value (-1 to exit): ");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        node* temp=(*root);
        while(1){            
            if (x<temp->data){
                if(temp->lchild==NULL){
                    temp->lchild=createNode(x); 
                    break;
                }
                else
                    temp=temp->lchild;
            }
            else if (x>temp->data){
                if(temp->rchild==NULL){
                    temp->rchild=createNode(x); 
                    break;
                }
                else
                    temp=temp->rchild;
            }
            else{
                break;;
            }
        }
    }
}

node** createTree(node** root,int val){
    int val;
    scanf("%d",&val);
    if(val==-1){
        return NULL;
    }
    return createNode(val);
    printf("Enter lchild: ");
    (*root)->lchild=createTree((*root)->lchild, val);
    printf("Enter rchild: ");
    (*root)->rchild=createTree((*root)->rchild, val);
    return root;
}

void inorder(node* root){
    if (root!=NULL){
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
} 

int main(){
    int x; 
    printf("Enter value of root: ");
    scanf("%d",&x);
    node* root=createNode(x);
    createTree(&root,x);
    inorder(root);
    return 0; 
}
