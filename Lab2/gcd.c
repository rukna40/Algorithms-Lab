#include <stdio.h>
#include <stdlib.h>


int opcount=0;
int euclidgcd(int m,int n){
    while (n>0){
        opcount++;
        int r=m%n;
        m=n;
        n=r;
    }
    return m;
}

int consintcheck(int m,int n){
    int t=m>n?m:n;
    while(t>0){
        if(m%t==0 && n%t==0)
            return t;
        t--;
    }
}

int main(){

    int m,n; 
    printf("Enter the two numbers whose GCD has to be calculated"); 
    scanf("%d %d", &m,&n); 
    printf("GCD of two numbers using euclidgcd method is: %d\n", euclidgcd(m,n));  
    printf("GCD of two numbers using consintcheck method is: %d", consintcheck(m,n));  

    return 0;
}