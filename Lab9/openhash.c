#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 10

typedef struct node{
    char word[MAX];
    struct node* next;
}node;

node* createNode(char word[]){
    node* newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->word,word);
    newnode->next=NULL;
    return newnode;
}

void insert(node* table[], char word[]){
    int m=strlen(word);
    if (!table[m])
        table[m]=createNode(word);
    else{
        node* temp=table[m];
        while(temp->next){
            temp=temp->next;
        }
        temp->next=createNode(word); 
    }
}

void display(node* table[]){
    for(int i=0;i<MAX;i++){
        node* temp=table[i];
        printf("%d --> ",i);
        while(temp){
            printf("%s\t",temp->word);
            temp=temp->next;
        }
        printf("\n");
    }
}

int search(node* table[], char word[]){
    for(int i=0;i<MAX;i++){
        node* temp=table[i];
        while(temp){
            if (strcmp(temp->word,word)==0)
                return i;
            temp=temp->next;
        }
    }
    return -1;
}

int main(){
    int n;
    char word[MAX];
    printf("Enter n: ");
    scanf("%d",&n);  

    node* table[MAX];
    for(int i=0;i<MAX;i++){
        table[i]=NULL;
    }
    getchar();
    for(int i=0;i<n;i++){
        printf("Enter word: ");
        fgets(word,10,stdin);
        word[strlen(word) - 1] = '\0';
        insert(table,word);
    }
    display(table);
    return 0;
}