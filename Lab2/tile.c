#include <stdio.h>

int tile(int n){
    if(n<=2)
        return n;

    int ways1=tile(n-1);
    int ways2=tile(n-2);
    
    return ways1+ways2; 
}