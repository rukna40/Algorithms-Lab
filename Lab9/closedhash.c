#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 10

void insert(char** table, char word[]){
    int m=strlen(word);
    int index=m%MAX;
    if (strlen(table[index]))
        index+=1;
    strcpy(table[index],word);    
}

void display(char** table){
    for(int i=0;i<MAX;i++){
        printf("%d --> %s\n",i,table[i]);        
    }
}

int search(char** table, char word[]){
    for(int i=0;i<MAX;i++){
        if(strcmp(table[i],word))
            return i;        
    }
    return -1;
}

int main(){
    int n;
    char word[MAX];
    printf("Enter n: ");
    scanf("%d",&n);  

    char** table=(char**)malloc(MAX*sizeof(char*));
    for(int i=0;i<MAX;i++){
        table[i] = (char*)malloc(MAX*sizeof(char));
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