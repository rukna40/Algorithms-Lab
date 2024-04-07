#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boyermoore(char text[],char pattern[]){
    int n=strlen(text);
    int m=strlen(pattern);
    int bs[128];
    int gs[m-1];
    for(int i=0;i<128;i++)
        bs[i]=m;
    for(int i=0;i<m;i++){
        bs[pattern[i]]=m-i-1;
    }
    for(int i=0;i<m-1;i++){
    }
}