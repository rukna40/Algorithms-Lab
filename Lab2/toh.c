#include <stdio.h>

void toh(int n, char source, char dest, char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",source,dest);
        return;
    }
    toh(n-1,source,aux,dest);
    printf("Move disk %d from %c to %c\n",n,source,dest);
    toh(n-1,aux,dest,source);
}

int main(){
    toh(5,'A','C','B');
}