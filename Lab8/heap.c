#include <stdio.h>
#include <stdlib.h>

void heapify(int n, int h[n]){
    int i,j,k,v,flag;
    for(i=n/2;i>=0;i--){
        flag=0;
        k=i;
        v=h[k];
        while(flag==0 && 2*k<=n){
            j=2*k;
            if(j<n)
                if(h[j]<h[j+1]) 
                    j=j+1;
            if (v>=h[j])
                flag=1;
            else{
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
    return;
}

void main(){ 
    int h[20],i,n; 

    printf("\nEnter the number of Elements:"); 
    scanf("%d",&n); 
    printf("\nEnter the Elements:"); 
    for(i=1;i<=n;i++) 
      scanf("%d",&h[i]); 
    printf("\ndisplay the array:"); 
    for(i=1;i<=n;i++) 
    { 
      printf("%d\t",h[i]); 
    } 
    heapify(n,h); 
    printf("\nThe heap created:"); 
    for(i=1;i<=n;i++) 
    { 
      printf("%d\t",h[i]); 
    } 
} 
 
