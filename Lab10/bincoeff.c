#include <stdio.h>
#include <stdlib.h>

int C(int n, int k){
    if(k>n){
        return 0;
    }
    if(k==0 || k==n){
        return 1;
    }
    return C(n-1,k-1)+C(n-1,k);
}

int min(int a,int b){
    return a<b?a:b;
}

int c[10][10]; 

int iterC(int n, int k){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if (j==0 || j==i){
                c[i][j] = 1; 
            }
            else{
                c[i][j] = c[i-1][j-1] + c[i-1][j]; 
            }
        }
    }
    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j <= 10; j++) {
    //         printf("%d ", c[i][j]);
    //     }
    //     printf("\n");
    // }
    return c[n][k];
}

int main(){
    printf("%d",iterC(6,3));
    return 0;
}
