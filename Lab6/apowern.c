#include <stdio.h>

int calc(int a,int n){
    
    if(n==0)
        return 1;

    int val=calc(a,n/2);
    
    if(n%2==0)
        return val*val;
    else
        return a*val*val;
}

int main(){
    printf("%d",calc(5,3));
}